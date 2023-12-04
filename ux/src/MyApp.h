#pragma once
#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <Ultralight/Ultralight.h>
#include <string>
#include <map>
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>

using namespace ultralight;
using std::string;
using std::map;

#define WINDOW_WIDTH    900
#define WINDOW_HEIGHT   600
#define LEFT_PANE_WIDTH 200

struct StringResult {
    std::string val;
    bool success;
};

class MyApp : public WindowListener, public ViewListener, public LoadListener {
    enum VIEW { SIDEBAR, DASHBOARD, SEARCH, HELP};  

    const struct VIEW_URL {
        ultralight::String SIDEBAR = "file:///sidebar.html";
        ultralight::String DASHBOARD = "file:///stats.html";
        ultralight::String SEARCH = "file:///search.html";
        ultralight::String HELP = "file:///help.html";
    } VIEW_URLS;

    RefPtr<App> app_;
    RefPtr<Window> window_;
    RefPtr<Overlay> left_pane_;
    RefPtr<Overlay> right_pane_;
    
    map<VIEW, RefPtr<Overlay>> overlays_;

    void setRightPane(RefPtr<Overlay> paneOverlay);
    string dbAuthKey;
    int width_, height_;
    RefPtr<JSContext> context_;

public:
    MyApp();
    virtual ~MyApp();

// Window Listener overrides
    virtual void OnClose(ultralight::Window* window) override;
    virtual void OnResize(ultralight::Window* window, uint32_t width, uint32_t height) override;
    virtual bool OnKeyEvent(const KeyEvent& evt) override;
    virtual bool OnMouseEvent(const MouseEvent& evt) override;
    virtual bool OnScrollEvent(const ScrollEvent& evt) override;

// View Listener overrides
    virtual void OnChangeCursor(ultralight::View* caller, ultralight::Cursor cursor) override;

// Load Listener overrides
    virtual void OnFailLoading(ultralight::View* caller,
        uint64_t frame_id,
        bool is_main_frame,
        const String& url,
        const String& description,
        const String& error_domain,
        int error_code);

    bool writeFile(string filename, string str_data);
    string readFile(string filename);

    void appendFav(string nextSearch);
    void Run();

    // init javascript here
    virtual void OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url);

    // Javascript functions
    //JSFunction updateMovieSearch;
    JSFunction returnGenreResults;

    // Sidebar functions
    JSValue btnDashboard(const JSObject& thisObject, const JSArgs& args);
    JSValue btnSearch(const JSObject& thisObject, const JSArgs& args);
    JSValue btnHelp(const JSObject& thisObject, const JSArgs& args);

    // Search
    JSValue sendFileToCpp(const JSObject& thisObject, const JSArgs& args);
    JSValue processGenreSearch(const JSObject& thisObject, const JSArgs& args);
};