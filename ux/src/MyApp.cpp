#include "MyApp.h"

#define debug

#define DOUT( s ) { \
    cout<<s<<endl;}

#ifdef debug
    
#endif
using std::make_pair;
using std::cout;
using std::endl;
using namespace ultralight;

static MyApp* g_ui = nullptr;

// returns json string of movies
JSValue MyApp::processGenreSearch(const JSObject& thisObject, const JSArgs& args) {
    String jString = args[0];
    char* cString = jString.utf8().data();
    string genreString = string(cString);

    string genreMoviesJson = ansis(genreString); 

    JSValue out(genreMoviesJson.c_str());

    returnGenreResults(JSArgs({out}));

    return JSValue(out);
}


MyApp::MyApp() {

    app_ = App::Create();
    window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT, false, (kWindowFlags_Titled | kWindowFlags_Resizable));

    window_->SetTitle("Movie Finder");
    g_ui = this;

    // Register WindowListener for OnResize and OnClick events
    window_->set_listener(this);

    // L/R pane overlays
    overlays_.insert(make_pair(VIEW::SIDEBAR, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::DASHBOARD, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::SEARCH, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::HELP, Overlay::Create(window_.get(), 100, 100, 0, 0)));


    // initial overlay setup
    for (std::pair<int, RefPtr<Overlay>> OL : overlays_) {
        // hidden
        OL.second->Hide();

        // set view (OnChangeCursor) and load (OnDOMReady) listeners
        OL.second->view()->set_view_listener(this);
        OL.second->view()->set_load_listener(this);
    }

    // Load overlay HTML views
    overlays_[VIEW::SIDEBAR]->view()->LoadURL(VIEW_URLS.SIDEBAR);
    overlays_[VIEW::DASHBOARD]->view()->LoadURL(VIEW_URLS.DASHBOARD);
    overlays_[VIEW::SEARCH]->view()->LoadURL(VIEW_URLS.SEARCH);
    overlays_[VIEW::HELP]->view()->LoadURL(VIEW_URLS.HELP);
    
    // set panes;
    left_pane_ = overlays_[VIEW::SIDEBAR];
    overlays_[VIEW::SIDEBAR]->Show();
    right_pane_ = overlays_[VIEW::DASHBOARD];
    setRightPane(overlays_[VIEW::DASHBOARD]);
}

MyApp::~MyApp() {
    // initial overlay setup
    for (std::pair<int, RefPtr<Overlay>> OL : overlays_) {
        OL.second->view()->set_view_listener(nullptr);
        OL.second->view()->set_load_listener(nullptr);
    }
    g_ui = nullptr;
}


// this should only be called by a bound function to keep the HTML active page in sync.
void MyApp::setRightPane(RefPtr<Overlay> paneOverlay) {
    right_pane_->Hide();
    right_pane_ = paneOverlay;
    OnResize(window_.get(), window_->width(), window_->height());
    RefPtr<JSContext> lock(right_pane_->view()->LockJSContext());
    right_pane_->Show();
    right_pane_->Focus();
    right_pane_->view()->Focus();
}


/////////////////////////////////////
//
// JAVASCRIPT BOUND FUNCTIONS
//
/////////////////////////////////////

JSValue MyApp::btnDashboard(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    right_pane_->view()->Unfocus();
    setRightPane(overlays_[MyApp::VIEW::DASHBOARD]);
    context_ = right_pane_->view()->LockJSContext();
    
    return JSValue("Dashboard");
}

JSValue MyApp::btnSearch(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    right_pane_->view()->Unfocus();
    setRightPane(overlays_[MyApp::VIEW::SEARCH]);
    right_pane_->view()->Focus();
    context_ = right_pane_->view()->LockJSContext();
    cout << "Search clicked." << endl;
    return JSValue("Search");
} 


JSValue MyApp::btnHelp(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    // ended work here trying to setup context_ to keep the focus on the textbox in search
    right_pane_->view()->Unfocus();
    setRightPane(overlays_[MyApp::VIEW::HELP]);
    context_ = right_pane_->view()->LockJSContext();
    cout << "Help clicked." << endl;
    return JSValue("Help");
}


JSValue MyApp::sendFileToCpp(const JSObject& thisObject, const JSArgs& args) {
//    Arguments indices:
    // 0: file name
    // 1: movie Json
    // 2: search term
    JSContextRef ctx = thisObject.context();    
    
    // Convert String to C++ string
    String jsSearch = args[2];
    char* cSearch = jsSearch.utf8().data();
    String jsStr = args[1];
    char* cStr = jsStr.utf8().data();
    String jsFilename = args[0];
    char* cFilename = jsFilename.utf8().data();
    string search = std::string(cSearch);
    string str = std::string(cStr);
    string filename = std::string(cFilename);
    
    appendFav(search);
    DOUT(str);
    writeFile(filename, str);
    
    return JSValue();
}

void MyApp::OnChangeCursor(ultralight::View* caller, ultralight::Cursor cursor) {
    if (App::instance()) {
        window_->SetCursor(cursor);
    }
}

void MyApp::appendFav(string term) {
    try {
        string fPath = "favs.json";
        // open and create file if not there.
        std::ofstream outfile;
        // Open the file, create if it does not exist
        outfile.open(fPath, std::ios_base::app);

        // Check if the file was opened successfully
        if (!outfile) {
            return;
        }
        std::streampos begin, end;
        begin = outfile.tellp();
        outfile.seekp(0, std::ios::end);
        end = outfile.tellp();
        /*
        if ((end-begin)<=1) {
            outfile << "[\n\"searches\"\n]" << endl;
        }
        */
        outfile.close();
        // Open the file in read/write mode
        std::ifstream in;
        {
            in.open(fPath, std::ios::binary);
            if (!in.is_open()) {
                return;
            }
        }

        // Read the existing JSON data
        string in_data;
        string bit;
        while (!in.eof()) {
            in >> bit;
            in_data = in_data + bit;
        }
        in.close();
        nlohmann::json data;
        if (in_data.size() > 0)
            data = nlohmann::json::parse(in_data);

        // Convert string to JSON object if possible
        nlohmann::json element_json = nlohmann::json(nullptr);
        try {
            element_json = element_json.parse("[\"term\", \""+term+"\"]");
        }
        catch (nlohmann::json::exception& e) {
            std::cerr << "Error parsing string as JSON: " << e.what() << std::endl;
            return;
        }

        // do nothing if null;
        if (!element_json.is_null()) {
            data.push_back(element_json); // Append as string
        }
        else
            return;
        
        // Open the file in write mode
        std::ofstream out(fPath, std::ios::binary);
        if (!out.is_open()) {
            return; // Error opening file
        }

        // Save the modified JSON data
        out << std::setw(2) << data; // Pretty-print with indentation of 2 spaces
        out.close();

        return; // Success
    }
    catch (std::exception& e) {
        std::cerr << "Error reading or writing JSON file: " << e.what() << std::endl;
        return; // Error reading/writing JSON
    }
}

void MyApp::Run() {
    app_->Run();
}


// Events
void MyApp::OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) {
    /// Set our View's JSContext
    RefPtr<JSContext> context = caller->LockJSContext();
    SetJSContext(context->ctx());
    
    /// Get the global object (this would be the "window" object in JS)
    JSObject global = JSGlobalObject();

    returnGenreResults = global["returnGenreResults"];
    global["btnDashboard"] = BindJSCallbackWithRetval(&MyApp::btnDashboard);
    global["btnSearch"] = BindJSCallbackWithRetval(&MyApp::btnSearch);
    global["btnHelp"] = BindJSCallbackWithRetval(&MyApp::btnHelp);
    
    global["sendFileToCpp"] = BindJSCallback(&MyApp::sendFileToCpp);   // for saving json file
    global["processGenreSearch"] = BindJSCallbackWithRetval(&MyApp::processGenreSearch);
}

// called when Window closed.
void MyApp::OnClose(ultralight::Window* window) {
    app_->Quit();
}

// called when Window resized.
void MyApp::OnResize(ultralight::Window* window, uint32_t width, uint32_t height) {
    uint32_t left_pane_width_px = window_->ScreenToPixels(LEFT_PANE_WIDTH);
    left_pane_->Resize(left_pane_width_px, height);

    // Calculate the width of our right pane (window width - left width)
    int right_pane_width = (int)width - left_pane_width_px;

    // Clamp our right pane's width to a minimum of 1
    right_pane_width = right_pane_width > 1 ? right_pane_width : 1;

    right_pane_->Resize((uint32_t)right_pane_width, height);

    left_pane_->MoveTo(0, 0);
    right_pane_->MoveTo(left_pane_width_px, 0);
}


bool MyApp::OnKeyEvent(const KeyEvent& evt) {
    return true;
}


bool MyApp::OnMouseEvent(const MouseEvent& evt) {
    switch (evt.type) {
    case MouseEvent::kType_MouseMoved: {
        break;
    }
    case MouseEvent::kType_MouseDown: {
        if (evt.button == MouseEvent::kButton_Left) { 
            ;
        }
        break;
    }
    case MouseEvent::kType_MouseUp: {
        if (evt.button == MouseEvent::kButton_Left) { ; }
        break;
    }
    }
    return true;
}

bool MyApp::OnScrollEvent(const ScrollEvent& evt) {
    return true;
}

void MyApp::OnFailLoading(ultralight::View* caller,
    uint64_t frame_id,
    bool is_main_frame,
    const String& url,
    const String& description,
    const String& error_domain,
    int error_code) {
}

bool MyApp::writeFile(string filename, string str_data) {
    cout << filename << " << " << str_data << endl;
    std::ofstream ofile = std::ofstream(filename);
    if (!ofile.bad()) {
        ofile << str_data;
        ofile.close();
        return true;
    }
    else {
        cout << "file write error." << endl;
    }
    ofile.close();
    return false;
}

string MyApp::readFile(string filename) {
    string file="";
    std::ifstream ifile = std::ifstream(filename);
    if (!ifile.bad()) {
        while (!ifile.eof()) {
            ifile >> file;
            ifile.close();
            return file;
        }
    }
    ifile.close();
    return file;
}



// analysis

string MyApp::time_diff(chrono::steady_clock::time_point start, chrono::steady_clock::time_point stop) {
    return to_string(duration_cast<chrono::microseconds>(stop - start).count());
}

string MyApp::movies_to_str(vector<Node_Sp*>& movies) {
    string result;
    result += "movies: [\n";
    for (int i = 0; i < movies.size() - 1; i++) {
        result += "{\n";
        result += R"(movieID: ")" + movies[i]->movieID + "\",\n";
        result += R"(title: ")" + movies[i]->movie + "\"";
        result += "\n},\n";
    }

    result += "{";
    result += R"(movieID: ")" + movies[movies.size() - 1]->movieID + "\",\n";
    result += R"(title: ")" + movies[movies.size() - 1]->movie + "\"";
    result += "}\n";
    result += "}\n],\n";

    return result;
}

string MyApp::duration_str(string tag, string time) {
    string final;
    final += " " + tag + ": " + time + ", ";
    return final;
}

string MyApp::ansis(string user_genre) {
    auto start = chrono::steady_clock::now();

    std::ifstream f("./assets/data/movie_data.json");
    SplayTree movie_tree_sp;
    RedBlackTree movie_tree_rb;

    string line;
    json movie_data = json::parse(f);

    // splay build

    auto build_start_sp = CLK_NOW;
    for (auto& i : movie_data) {
        string mv_title = i["primaryTitle"];
        string mv_id = i["tconst"];

        string year;
        year = i["startYear"];
        int mv_year = 0;
        if (year == (R"(\\N)") || year == (R"(\N)")) {
            mv_year = -1;
        }
        else {
            mv_year = stoi(year);
        }
        string mv_genres = i["genres"];
        string mv_category;
        if (mv_genres == (R"(\\N)") || mv_genres == (R"(\N)")) {
            mv_category = "";
        }
        else if (mv_genres.find(',') != string::npos) {
            mv_category = mv_genres.substr(0, mv_genres.find(','));
        }
        else {
            mv_category = mv_genres;
        }

        movie_tree_sp.insert(mv_year, mv_title, mv_category, mv_id);
    }
    auto build_end_sp = CLK_NOW;
    string build_time_sp = time_diff(build_start_sp, build_end_sp);

    // rb build
    auto build_start_rb = CLK_NOW;
    for (auto& i : movie_data) {
        string mv_title = i["primaryTitle"];
        string mv_id = i["tconst"];

        string year;
        year = i["startYear"];
        int mv_year = 0;
        if (year == (R"(\\N)") || year == (R"(\N)")) {
            mv_year = -1;
        }
        else {
            mv_year = stoi(year);
        }

        string mv_genres = i["genres"];
        string mv_category;
        if (mv_genres == (R"(\\N)") || mv_genres == (R"(\N)")) {
            mv_category = "";
        }
        else if (mv_genres.find(',') != string::npos) {
            mv_category = mv_genres.substr(0, mv_genres.find(','));
        }
        else {
            mv_category = mv_genres;
        }

        movie_tree_rb.insert(mv_year, mv_title, mv_category, mv_id);
    }
    auto build_end_rb = CLK_NOW;
    string build_time_rb = time_diff(build_start_rb, build_end_rb);

    vector<Node_Sp*> result_movies_sp;
    vector<RB_Node*> result_movies_rb;

    // splay search
    auto search_start_sp = CLK_NOW;
    movie_tree_sp.search(result_movies_sp, user_genre);
    auto search_end_sp = CLK_NOW;
    string search_time_sp = time_diff(search_start_sp, search_end_sp);

    // rb search
    auto search_start_rb = CLK_NOW;
    movie_tree_rb.search(result_movies_rb, user_genre);
    auto search_end_rb = CLK_NOW;
    string search_time_rb = time_diff(search_start_rb, search_end_rb);

    // json conversions
    string movies_json = movies_to_str(result_movies_sp);
    string movie_html = "movies: [ ";
    for (auto m : result_movies_rb) {
        movie_html = movie_html + "{ tconst: " + m->movieID + "}, ";
    }
    movie_html = movie_html + " ] ";
    string total_results = "total_results: " + to_string(result_movies_rb.size()) + ", ";
    string search_time_rb_json = duration_str("search_time_rb", search_time_rb);
    string search_time_sp_json = duration_str("search_time_sp", search_time_sp);
    string build_time_rb_json = duration_str("build_time_rb", build_time_rb);
    string build_time_sp_json = duration_str("build_time_sp", build_time_sp);

    string json_string = "\'{ "  + total_results + build_time_rb_json + build_time_sp_json +
                                search_time_rb_json + search_time_sp_json +
                                movie_html + " }\'";

    return json_string;
}