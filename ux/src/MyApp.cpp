#include "MyApp.h"
#include <iostream>

using std::make_pair;
using std::cout;
using std::endl;
using namespace ultralight;

MyApp::MyApp() {
    // main ultralight App instance.
    app_ = App::Create();

    // resizable via - OR'ing window flags with kWindowFlags_Resizable.
    window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT, false, (kWindowFlags_Titled | kWindowFlags_Resizable));

    // window title.
    window_->SetTitle("Movie Finder");

    // Register WindowListener for OnResize and OnClick events
    window_->set_listener(this);

    // L/R pane overlays
    overlays_.insert(make_pair(VIEW::SIDEBAR, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::DASHBOARD, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::SEARCH, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::FAVORITES, Overlay::Create(window_.get(), 100, 100, 0, 0)));
    overlays_.insert(make_pair(VIEW::HELP, Overlay::Create(window_.get(), 100, 100, 0, 0)));


    // initial overlay setup
    for (std::pair<int, RefPtr<Overlay>> OL : overlays_) {
        // hidden
        OL.second->Hide();

        // set view (OnChangeCursor) and load (OnDOMReady) listeners
        OL.second->view()->set_view_listener(this);
        OL.second->view()->set_load_listener(this);
    }

    // button event listeners
    
 
    // set panes;
    left_pane_ = overlays_[VIEW::SIDEBAR];
    right_pane_ = overlays_[VIEW::DASHBOARD];

    // Load overlay HTML views
    overlays_[VIEW::SIDEBAR]->view()->LoadURL(VIEW_URLS.SIDEBAR);
    overlays_[VIEW::DASHBOARD]->view()->LoadURL(VIEW_URLS.DASHBOARD);
    overlays_[VIEW::SEARCH]->view()->LoadURL(VIEW_URLS.SEARCH);
    overlays_[VIEW::FAVORITES]->view()->LoadURL(VIEW_URLS.FAVORITES);
    overlays_[VIEW::HELP]->view()->LoadURL(VIEW_URLS.HELP);
    
    // set initial layout and sizing, defines gl clipping bounds
    OnResize(window_.get(), window_->width(), window_->height());

    // show start with sidebar and dashboard
    overlays_[VIEW::SIDEBAR]->Show();
    overlays_[VIEW::DASHBOARD]->Show();
}

MyApp::~MyApp() {
}


// this should only be called by a bound function to keep the HTML active page in sync.
void MyApp::setRightPane(RefPtr<Overlay> paneOverlay) {
    right_pane_->Hide();
    right_pane_ = paneOverlay;
    OnResize(window_.get(), window_->width(), window_->height());
    right_pane_->Show();
    right_pane_->Focus();
}


/////////////////////////////////////
//
// JAVASCRIPT BOUND FUNCTIONS
//
/////////////////////////////////////
JSValue MyApp::btnSearchSubmit(const JSObject& thisObject, const JSArgs& args) {
    // button pressed so now there is a new json file ready for us.
    // generate new stats
    // update search history
    return JSValue("");
}

JSValue MyApp::btnDashboard(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    setRightPane(overlays_[MyApp::VIEW::DASHBOARD]);
    cout << "Dashboard clicked." << endl;
    return JSValue("Dashboard");
}

JSValue MyApp::btnSearch(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    setRightPane(overlays_[MyApp::VIEW::SEARCH]);
    cout << "Search clicked." << endl;
    return JSValue("Search");
} 

JSValue MyApp::btnFavorites(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    setRightPane(overlays_[MyApp::VIEW::FAVORITES]);
    cout << "Favorites clicked." << endl;
    return JSValue("Favorites");
}

JSValue MyApp::btnHelp(const JSObject& thisObject, const JSArgs& args) {
    // load proper view
    setRightPane(overlays_[MyApp::VIEW::HELP]);
    cout << "Help clicked." << endl;
    return JSValue("Help");
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

    
    /// BOUND FUNCTION GUIDE
    /// Bind MyApp::boundFuntion to the JavaScript function named "boundFunct".
    ///
    /// You can get/set properties of JSObjects by using the [] operator with the following types
    /// as potential property values:
    ///  - JSValue
    ///      Represents a JavaScript value, eg String, Object, Function, etc.
    ///  - JSCallback 
    ///      Typedef of std::function<void(const JSObject&, const JSArgs&)>)
    ///  - JSCallbackWithRetval 
    ///      Typedef of std::function<JSValue(const JSObject&, const JSArgs&)>)
    ///
    /// We use the BindJSCallbackWithRetval macro to bind our C++ class member function to our
    /// JavaScript callback.
    ///
    global["btnDashboard"] = BindJSCallbackWithRetval(&MyApp::btnDashboard);
    global["btnSearch"] = BindJSCallbackWithRetval(&MyApp::btnSearch);
    global["btnFavorites"] = BindJSCallbackWithRetval(&MyApp::btnFavorites);
    global["btnHelp"] = BindJSCallbackWithRetval(&MyApp::btnHelp);
    
    global["searchMovies"] = BindJSCallbackWithRetval(&MyApp::btnSearchSubmit);
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


void MyApp::OnChangeFocus(bool focused) {
    
}

bool MyApp::OnKeyEvent(const KeyEvent& evt) {
    if (evt.kType_Char == evt.type) {
        right_pane_;
        return true;
    }
    return false;
}


bool MyApp::OnMouseEvent(const MouseEvent& evt) {
    switch (evt.type) {
    case MouseEvent::kType_MouseMoved: {
        break;
    }
    case MouseEvent::kType_MouseDown: {
        if (evt.button == MouseEvent::kButton_Left) { ; }
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