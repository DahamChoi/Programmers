#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, pair<int, vector<pair<int, int>>>> play_map;
    for (int i = 0; i < genres.size(); i++) {
        play_map[genres[i]].first += plays[i];
        play_map[genres[i]].second.push_back({ plays[i], i });
    }

    for (auto it = play_map.begin(); it != play_map.end(); it++) {
        sort((*it).second.second.begin(), (*it).second.second.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
            });
    }

    vector<pair<string, pair<int, vector<pair<int, int>>>>> play_list(play_map.begin(), play_map.end());
    sort(play_list.begin(), play_list.end(), [](const pair<string, pair<int, vector<pair<int, int>>>>& p1,
        const pair<string, pair<int, vector<pair<int, int>>>>& p2) {
            return p1.second.first > p2.second.first;
        });

    for (int i = 0; i < play_list.size(); i++) {
        for (int j = 0; j < play_list[i].second.second.size() && j < 2; j++) {
            answer.push_back(play_list[i].second.second[j].second);
        }
    }

    return answer;
}

int main()
{
    vector<int> answer = solution({ "classic","pop","classic","classic","pop" }, { 500,600,150,800,2500 });
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}