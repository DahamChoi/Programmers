#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Page {
    int defaultScore{ 0 };
    float linkScore{ 0.f };
    string url;
    vector<string> link;

    explicit Page(const string& str, const string& word) {
        // URL
        auto urlPos = str.find("<meta property=\"og:url\" content=\"https://");
        auto urlPosEnd = str.find("\"", urlPos + 33);
        url = str.substr(urlPos + 33, urlPosEnd - urlPos - 33);

        // LINK
        auto linkPos = str.find("<a href=");
        while (linkPos != string::npos) {
            auto linkPosEnd = str.find("\">", linkPos);
            link.push_back(str.substr(linkPos + 9, linkPosEnd - linkPos - 9));
            linkPos = str.find("<a href=", linkPosEnd);
        }

        // DEFAULT SCORE
        int start = 0, end = 0, index = 0;
        while (index < str.length()) {
            if (!IsAlphaRange(str[index++])) {
                if (IsSameWord(str.substr(start, index - start - 1), word)) {
                    ++defaultScore;
                }

                start = index;
            }
        }
    }

    bool IsAlphaRange(const char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }

    bool IsSameWord(const string& str1, const string& str2) {
        if (str1.size() != str2.size())
            return false;
        
        for (int i = 0; i < str1.size() || i < str2.size(); i++) {
            char c1 = str1[i], c2 = str2[i];
            if (str1[i] >= 'A' && str1[i] <= 'Z') {
                c1 = c1 - ('A' - 'a');
            }

            if (str2[i] >= 'A' && str2[i] <= 'Z') {
                c2 = c2 - ('A' - 'a');
            }

            if (c1 != c2)
                return false;
        }

        return true;
    }
};

int solution(string word, vector<string> pages) {
    int answer = 0;

    vector<Page> pageList;
    for (auto i = 0; i < pages.size(); i++) {
        pageList.push_back(Page{ pages[i], word });
    }

    for (int i = 0; i < pageList.size(); i++) {
        for (int j = 0; j < pageList[i].link.size(); j++) {
            for (int k = 0; k < pageList.size(); k++) {
                if (i == k)
                    continue;

                if (pageList[i].link[j] == pageList[k].url) {
                    pageList[k].linkScore += (pageList[i].defaultScore / (float)pageList[i].link.size());
                }
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < pageList.size(); i++) {
        if ((pageList[i].defaultScore + pageList[i].linkScore) - (pageList[maxIndex].defaultScore + pageList[maxIndex].linkScore) > 0.001f) {
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main()
{
    vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
    cout << solution("blind", pages);
}