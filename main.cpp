#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shellapi.h>
#include <vector>


using namespace std;

string google = "https://www.google.com/search?q=";
string naver = "https://search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=0&ie=utf8&query=";
string youtube = "https://www.youtube.com/results?search_query=";
string daum = "https://search.daum.net/search?w=tot&q=";
string kw = "https://www.kw.ac.kr/ko/info/search.jsp?mode=list&srSearchField=all&srSearchOperator=or&searchVal=";
string stackoverflow = "https://stackoverflow.com/search?q=";
string danawa = "https://search.danawa.com/dsearch.php?k1=";
string fow = "http://fow.kr/find/";
string chrome = "chrome";
string edge = "msedge";
string iexplorer = "iexplore";

enum site
{
    GOOGLE=1,
    NAVER,
    YOUTUBE,
    DAUM,
    KW,
    STACKOVERFLOW,
    DANAWA,
    FOW
};
enum browser
{
    CHROME=1, EDGE, IEXPLORER
};

wstring s2ws(const string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    wstring r(buf);
    delete[] buf;
    return r;
}
void openSearch(string site, string brows, string word)
{
    string url;
    wstring urlTemp;
    LPCWSTR urlResult;
    wstring browserTemp;
    LPCWSTR browserResult;
    url = site + word;
    urlTemp = s2ws(url);
    urlResult = urlTemp.c_str();
    browserTemp = s2ws(brows);
    browserResult = browserTemp.c_str();
    ShellExecute(NULL, L"open", browserResult, urlResult, NULL, SW_SHOW);
}

void doSwitch(int countSite, int countBrowser, string searchWord)
{
    switch (countSite)
    {
    case site::GOOGLE:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(google, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(google, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(google, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::NAVER:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(naver, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(naver, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(naver, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::YOUTUBE:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(youtube, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(youtube, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(youtube, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::DAUM:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(daum, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(daum, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(daum, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::KW:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(kw, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(kw, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(kw, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::STACKOVERFLOW:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(stackoverflow, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(stackoverflow, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(stackoverflow, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::DANAWA:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(danawa, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(danawa, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(danawa, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    case site::FOW:
        switch (countBrowser)
        {
        case browser::CHROME:
            openSearch(fow, chrome, searchWord);
            break;
        case browser::EDGE:
            openSearch(fow, edge, searchWord);
            break;
        case browser::IEXPLORER:
            openSearch(fow, iexplorer, searchWord);
            break;
        default:
            cout << "ERROR!";
            break;
        }
        break;
    default:
        cout << "ERROR!";
        break;
    }
}

int main(void)
{
    int countSite = 0;
    int countBrowser = 0;
    string searchWord;
    cout << "0. 구글\n" << "1. 네이버\n" << "2. 유튜브\n" << "3. 다음\n" << "4. 광운대\n" << "5. 스택오버플로\n" << "6. 다나와\n" << "7. 포우\n" << "검색할 사이트를 선택하세요. : ";
    cin >> countSite;
    cin.ignore();
    cout << "\n0. 크롬\n" << "1. 엣지\n" << "2. 익스플로러\n" << "브라우저를 선택하세요 : ";
    cin >> countBrowser;
    cin.ignore();
    cout << "\n검색어를 입력하세요. : ";
    getline(cin, searchWord);
    doSwitch(countSite, countBrowser, searchWord);
}