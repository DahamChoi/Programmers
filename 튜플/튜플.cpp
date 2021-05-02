#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(string s, string delimiter) {
    vector<string> result;

    auto pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        string token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    if (!s.empty()) {
        result.push_back(s);
    }

    return result;
}

vector<int> solution(string s) {
    vector<int> answer;

    s.pop_back();
    s.erase(s.begin());
    vector<string> split = split_string(s, "}");

    split.front().erase(split.front().begin());
    for (int i = 1; i < split.size(); i++) {
        split[i].erase(split[i].begin(), split[i].begin() + 2);
    }

    vector<vector<int>> tuple_list(split.size());

    for (int i = 0; i < split.size(); i++) {
        vector<string> numbers = split_string(split[i], ",");
        for (int j = 0; j < numbers.size(); j++) {
            tuple_list[i].push_back(atoi(numbers[j].c_str()));
        }
    }

    sort(tuple_list.begin(), tuple_list.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1.size() < v2.size();
        });

    for (int i = 0; i < tuple_list.size(); i++) {
        for (int j = 0; j < tuple_list[i].size(); j++) {
            if (find(answer.begin(), answer.end(), tuple_list[i][j]) == answer.end()) {
                answer.push_back(tuple_list[i][j]);
                break;
            }
        }
    }

    return answer;
}

int main(){
    vector<int> answer = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}