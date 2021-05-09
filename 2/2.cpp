#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    long long value{ 0 }, index{ 0 };
    vector<edge*> nodes;
};

vector<edge*> edge_list;
long long answer = 0, sum = 0;

void dfs2(int from, int to) {
    for (auto it : edge_list[to]->nodes) {
        if (it->index != from) {
            dfs2(to, it->index);
        }
    }

    edge_list[from]->value += edge_list[to]->value;
    answer += abs(edge_list[to]->value);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    for (int i = 0; i < a.size(); i++) {
        edge_list.push_back(new edge{ a[i], i });
        sum += a[i];
    }

    if (sum != 0) {
        return -1;
    }

    for (int i = 0; i < edges.size(); i++) {
        edge_list[edges[i][0]]->nodes.push_back(edge_list[edges[i][1]]);
        edge_list[edges[i][1]]->nodes.push_back(edge_list[edges[i][0]]);
    }

    dfs2(0, 0);

    return answer;
}

int main()
{
    std::cout << solution({ -5, 0, 2, 1, 2 }, { {0,1},{3,4},{2,3},{0,3} });
}