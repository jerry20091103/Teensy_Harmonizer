#ifndef PAGES_H
#define PAGES_H

#define MAX_PAGE 2

enum pages
{
    PITCH_PAGE,
    MIX_PAGE
};

// Pages class
// A virtual class for other pages to inherit from
class Pages
{
public:
    // Page button press callback function
    virtual void onBtnPressed(unsigned char pin) = 0;
    // Page button release callback function
    virtual void onBtnReleased(unsigned char pin) = 0;
    // Page encoder callback function
    virtual void onEncTurned(unsigned char id, int value) = 0;
    // Configure a page before swithcing to it. Sets encoders and prepare variables.
    virtual void configurePage() = 0;

    // this updates the page on a constant interval
    virtual void update() = 0;
    // this draws stuff on the lcd
    virtual void draw() = 0;
    // Initialize a page at program startup
    virtual void init() = 0;

    int pageID;
};

// PagesManager class
// A Singleton class to store and manage all pages
class PageManager_
{
public:
    static PageManager_ &getInstance();
    // this array stores all page instances
    Pages *PageArr[MAX_PAGE];
    
    // Gets the current Page pointer on the screen
    Pages *getCurPage();
    // Initial all pages at program start
    void Init();
    // Switch to a page, will call configrePage before switching
    void switchPage(int pageID);

private:
    PageManager_() {}
    int currentPageId;
};

extern PageManager_ &PageManager;

#endif