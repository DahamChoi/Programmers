#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    unordered_map<string, int> str_map_1, str_map_2;

    for (int i = 0; i < str1.length(); i++) {
        str1[i] = toupper(str1[i]);
    }

    for (int i = 0; i < str2.length(); i++) {
        str2[i] = toupper(str2[i]);
    }

    for (int i = 0; i < str1.length() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            ++str_map_1[str1.substr(i, 2)];
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            ++str_map_2[str2.substr(i, 2)];
        }
    }

    int a = 0, b = 0;
    for (auto it = str_map_1.begin(); it != str_map_1.end(); it++) {
        if (str_map_2[it->first] >= 1) {
            a += min(str_map_2[it->first], it->second);
        }

        b += max(str_map_2[it->first], it->second);
    }

    for (auto it = str_map_2.begin(); it != str_map_2.end(); it++) {
        if (str_map_1[it->first] == 0) {
            b += it->second;
        }
    }

    return b == 0 ? 65536 : a / (double)b * 65536;
}

int main()
{
    std::cout << "Hello World!\n";
}