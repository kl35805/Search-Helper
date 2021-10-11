#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shellapi.h>
#include <vector>

using namespace std;

vector<string> Urls;
vector<string> Sites;
vector<string> Browsers;

void showUrls(void)
{
	int num = 1;
	cout << "----URL 목록--------------------" << '\n';
	for (string x : Urls)
	{
		cout << num << ". " << x << '\n';
		num++;
	}
	cout << "-----------------------------------" << "\n\n";
}

void showSites(void)
{
	int num = 1;
	cout << "----사이트 목록--------------------" << '\n';
	for (string x : Sites)
	{
		cout << num << ". " << x << '\n';
		num++;
	}
	cout << "-----------------------------------" << "\n\n";
}

void showBrowsers(void)
{
	int num = 1;
	cout << "----브라우저 목록------------------" << '\n';
	for (string x : Browsers)
	{
		cout << num << ". " << x << '\n';
		num++;
	}
	cout << "-----------------------------------" << "\n\n";
}

void makeUrls(void)
{
	ifstream fin("url.txt");
	if (fin.fail())
	{
		cerr << "Failed to load!" << '\n';
		exit(100);
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		Urls.push_back(line);
	}
	showUrls();
	fin.close();
}

void makeSites(void)
{
	ifstream fin("site.txt");
	if (fin.fail())
	{
		cerr << "Failed to load!" << '\n';
		exit(100);
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		Sites.push_back(line);
	}
	showSites();
	fin.close();
}

void makeBrowsers(void)
{
	ifstream fin("browser.txt");
	if (fin.fail())
	{
		cerr << "Failed to load!" << '\n';
		exit(100);
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		Browsers.push_back(line);
	}
	showBrowsers();
	fin.close();
}

void reloadList(void)
{
	ofstream foutUrl("url.txt");
	ofstream foutSite("site.txt");
	ofstream foutBrowser("browser.txt");
	for (int i = 0; i < Urls.size(); i++)
	{
		if (i == Urls.size() - 1)
			foutUrl << Urls[i];
		else
			foutUrl << Urls[i] << endl;
	}
	for (int i = 0; i < Sites.size(); i++)
	{
		if (i == Sites.size() - 1)
			foutSite << Sites[i];
		else
			foutSite << Sites[i] << endl;
	}
	for (int i = 0; i < Browsers.size(); i++)
	{
		if (i == Browsers.size() - 1)
			foutBrowser << Browsers[i];
		else
			foutBrowser << Browsers[i] << endl;
	}
	foutUrl.close();
	foutSite.close();
	foutBrowser.close();
}

void addUrlAndSite(void)
{
	string urlName;
	string siteName;
	cout << "사이트 주소를 입력하세요. : ";
	cin >> urlName;
	cin.ignore();
	cout << "사이트 이름을 입력하세요. : ";
	cin >> siteName;
	cin.ignore();
	Urls.push_back(urlName);
	Sites.push_back(siteName);
	reloadList();
	showUrls();
	showSites();
}

void delUrlAndSite(void)
{
	int pos;
	cout << "제거할 사이트의 번호를 입력하세요. : ";
	cin >> pos;
	Urls.erase(Urls.begin() + pos - 1);
	Sites.erase(Sites.begin() + pos - 1);
	reloadList();
	showUrls();
	showSites();
}

void addBrowser(void)
{
	string browserName;
	cout << "브라우저의 원래의 파일명을 정확하게 입력하세요! : ";
	cin >> browserName;
	Browsers.push_back(browserName);
	reloadList();
	showBrowsers();
}

void delBrowser(void)
{
	int pos;
	cout << "제거할 브라우저의 번호를 입력하세요. : ";
	cin >> pos;
	Browsers.erase(Browsers.begin() + pos - 1);
	reloadList();
	showBrowsers();
}

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

void readyToSearch(void)
{
	int siteNum = 0;
	int browserNum = 0;
	string searchWord;
	cout << "검색을 할 사이트의 번호를 입력하세요. : ";
	cin >> siteNum;
	cin.ignore();
	cout << "브라우저의 번호를 입력하세요. : ";
	cin >> browserNum;
	cin.ignore();
	cout << "검색어를 입력하세요. : ";
	cin >> searchWord;
	cin.ignore();
	openSearch(Urls[siteNum - 1], Browsers[browserNum - 1], searchWord);
}

void manyCases(void)
{
	int a;
	while (1)
	{
		cout << "add site = 1\ndel site = 2\nexit = 3\nadd browser = 4\ndel browser = 5\nSearch = 6\n: ";
		cin >> a;
		if (a == 1)
			addUrlAndSite();
		else if (a == 2)
			delUrlAndSite();
		else if (a == 3)
		{
			cout << "Thank you!";
			return;
		}
		else if (a == 4)
			addBrowser();
		else if (a == 5)
			delBrowser();
		else if (a == 6)
			readyToSearch();
		else
			cout << "다시 입력하세요.\n";
	}
}

int main(void)
{
	makeUrls();
	makeSites();
	makeBrowsers();
	manyCases();
}