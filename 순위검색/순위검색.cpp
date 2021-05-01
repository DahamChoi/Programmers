#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct information {
    string language, occupation, career, soul_food;
    int score;
};

vector<string> split_string(string s, string delimiter) {
    vector<string> result;

    auto pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        string token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    result.push_back(s);

    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());

    vector<string> vv1 = { "java", "python", "cpp" };
    vector<string> vv2 = { "backend" , "frontend" };
    vector<string> vv3 = { "junior", "senior" };
    vector<string> vv4 = { "pizza", "chicken" };

    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> info_map;
    for (int i = 0; i < info.size(); i++) {
        vector<string> split_list = split_string(info[i], " ");
        info_map[split_list[0]][split_list[1]][split_list[2]][split_list[3]].push_back(atoi(split_list[4].c_str()));
    }

    for (auto& it : info_map) {
        for (auto& it2 : it.second) {
            for (auto& it3 : it2.second) {
                for (auto& it4 : it3.second) {
                    sort(it4.second.begin(), it4.second.end());
                }
            }
        }
    }

    for (int q = 0; q < query.size(); q++) {
        vector<string> split_list = split_string(query[q], " and ");
        vector<string> split_list_2 = split_string(split_list[3], " ");

        vector<string> v1 = { split_list[0] }, v2 = { split_list[1] }, v3 = { split_list[2] }, v4 = { split_list_2[0] };
        if (v1.front() == "-") {
            v1 = vv1;
        }

        if (v2.front() == "-") {
            v2 = vv2;
        }

        if (v3.front() == "-") {
            v3 = vv3;
        }

        if (v4.front() == "-") {
            v4 = vv4;
        }

        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                for (int k = 0; k < v3.size(); k++) {
                    for (int l = 0; l < v4.size(); l++) {
                        auto& vc = info_map[v1[i]][v2[j]][v3[k]][v4[l]];
                        answer[q] += (vc.end() - lower_bound(vc.begin(), vc.end(), atoi(split_list_2[1].c_str())));
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> answer = solution(info, query);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}