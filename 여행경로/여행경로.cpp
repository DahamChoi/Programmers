#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int max_depth = 0;
vector<vector<string>> answer_list;

void travel(unordered_map<string, vector<string>>& airport_map, string airport, vector<string> history, int depth) {
    history.push_back(airport);

    if (depth >= max_depth - 1) {
        answer_list.push_back(history);
        return;
    }

    vector<string> v = airport_map[airport];
    for (int i = 0; i < v.size(); i++) {
        string s = v[i];
        airport_map[airport].erase(find(airport_map[airport].begin(), airport_map[airport].end(), s));
        travel(airport_map, s, history, depth + 1);
        airport_map[airport].push_back(s);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<string>> airport_map;

    for (int i = 0; i < tickets.size(); i++) {
        airport_map[tickets[i][0]].push_back(tickets[i][1]);
    }

    max_depth = tickets.size() + 1;

    vector<string> history;
    travel(airport_map, "ICN", history, 0);

    sort(answer_list.begin(), answer_list.end());
    
    return answer_list.front();
}

int main()
{
    vector<vector<string>> tickets = { {"ICN","JFK"}, {"HND","IAD"}, {"JFK","HND"} };
    vector<vector<string>> tickets2 = { {"ICN","SFO"}, {"ICN","ATL"}, {"SFO","ATL"}, {"ATL","ICN"}, {"ATL","SFO"} };
    vector<string> answer = solution(tickets2);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}
