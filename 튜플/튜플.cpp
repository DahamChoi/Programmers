#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> list;

    for (int i = 1; i < s.length() - 1;) {
        if (s[i] == '{') {
            vector<int> temp_list;
            int j = i + 1;
            while (j < s.length() && s[j] != '}') {
                int k = j;
                while ((k = s.find(',', k)) != string::npos) {
                    temp_list.push_back(atoi(s.substr(j, k - j).c_str()));
                    j = k + 1;
                }
            }
            list.push_back(temp_list);
            i = j + 1;
        }
    }

    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }

    return answer;
}

int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}