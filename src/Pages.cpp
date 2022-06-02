#include "Pages.h"
#include "PitchPage.h"
#include "MixPage.h"

PageManager_ &PageManager_::getInstance()
{
    static PageManager_ instance;
    return instance;
}

PageManager_ &PageManager = PageManager.getInstance();

Pages* PageManager_::getCurPage()
{
    return PageArr[currentPageId];
}

void PageManager_::Init()
{
    PageArr[PITCH_PAGE] = new PitchPage();
    PageArr[MIX_PAGE] = new MixPage();

    for(auto i : PageArr)
    {
        if(i == nullptr)
            continue;
        i->init();
    }
}

void PageManager_::switchPage(int pageID)
{   
    currentPageId = pageID;
    PageArr[pageID]->configurePage();
}