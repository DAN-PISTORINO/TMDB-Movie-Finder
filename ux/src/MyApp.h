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
    enum VIEW { SIDEBAR, DASHBOARD, SEARCH, FAVORITES, HELP};  

    const struct VIEW_URL {
        ultralight::String SIDEBAR = "file:///sidebar.html";
        ultralight::String DASHBOARD = "file:///stats.html";
        ultralight::String SEARCH = "file:///search.html";
        ultralight::String FAVORITES = "file:///favorites.html";
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


public:
    MyApp();
    virtual ~MyApp();

// Window Listener overrides
    // called when Window closed.
    virtual void OnClose(ultralight::Window* window);
    // called when Window resized.
    virtual void OnResize(ultralight::Window* window, uint32_t width, uint32_t height);
    // other events
    virtual void OnChangeFocus(bool focused);
    virtual bool OnKeyEvent(const KeyEvent& evt);
    virtual bool OnMouseEvent(const MouseEvent& evt);
    virtual bool OnScrollEvent(const ScrollEvent& evt);
    //virtual void OnAddConsoleMessage(ultralight::View* caller, MessageSource source,
    //    MessageLevel level, const String& message, uint32_t line_);
    
// View Listener overrides
    // called when Cursor changes.
    //virtual void OnChangeCursor(ultralight::View* caller, ultralight::Cursor cursor) override;

// Load Listener overrides
    virtual void OnFailLoading(ultralight::View* caller,
        uint64_t frame_id,
        bool is_main_frame,
        const String& url,
        const String& description,
        const String& error_domain,
        int error_code);

// Javascript functions
    // init javascript here
    virtual void OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url);
    // bound functions
    JSValue btnDashboard(const JSObject& thisObject, const JSArgs& args);
    JSValue btnSearch(const JSObject& thisObject, const JSArgs& args);
    JSValue btnFavorites(const JSObject& thisObject, const JSArgs& args);
    JSValue btnHelp(const JSObject& thisObject, const JSArgs& args);
    JSValue btnSearchSubmit(const JSObject& thisObject, const JSArgs& args);

    JSValue GetStringFromJS(const JSObject& thisObject, const JSArgs& args);

    bool writeFile(string filename, string str_data);
    string readFile(string filename);


    void Run();
};