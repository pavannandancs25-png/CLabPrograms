//leetcode
#include <string.h>


typedef struct {
    char ** urls;
    int top;
    int curr;
    int cap;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory *browser = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    if(browser == NULL){
        return NULL;
    }
    browser->cap = 8;
    browser->urls = (char**)malloc(browser->cap * sizeof(char*));
    browser->urls[0] = strdup(homepage);
    browser->top=0;
    browser->curr=0;
    return browser;
}

void browserHistoryVisit(BrowserHistory* browser, char* url) {
    browser->curr++;

    for(int i = browser->curr; i <= browser->top;i++){
        free(browser->urls[i]);
    }

    if(browser->curr == browser->cap) {
        browser->cap*=2;
        browser->urls = (char**)realloc(browser->urls,browser->cap*sizeof(char*));
    }

    browser->urls[browser->curr] = strdup(url);
    browser->top = browser->curr;
    

}

char* browserHistoryBack(BrowserHistory* browser, int steps) {
    if(browser->curr-steps >= 0){
        browser->curr-=steps;
        return browser->urls[browser->curr];
    }
    browser->curr=0;
    return browser->urls[browser->curr];
}

char* browserHistoryForward(BrowserHistory* browser, int steps) {
    if(browser->curr+steps <= browser->top){
        browser->curr+=steps;
        return browser->urls[browser->curr];
    }
    browser->curr=browser->top;
    return browser->urls[browser->top];
}

void browserHistoryFree(BrowserHistory* browser) {
    for(int i=0;i<=browser->top;i++){
        free(browser->urls[i]);
    }
    free(browser->urls);
    free(browser);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/