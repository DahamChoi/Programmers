#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int target_node;
    int weight;
    Edge(int t, int w) : target_node{ t }, weight{ w } {}
};

struct Graph {
    Graph(int size) {
        for (int i = 0; i < size; i++) {
            nodes.push_back(vector<Edge>());
        }
    }
    
    void AddEdge(int node1, int node2, int weight) {
        nodes[node1].push_back(Edge(node2, weight));
        nodes[node2].push_back(Edge(node1, weight));
    }

    int GetDistance(int from, int to) {
        vector<int> dist(nodes.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[from] = 0;
        pq.push(pair<int, int>(0, from));
        while (!pq.empty()) {
            int curr = pq.top().second;
            pq.pop();
            for (auto& it : nodes[curr]) {
                int next = it.target_node;
                int cost = it.weight;
                if (dist[next] < 0 || dist[next] > dist[curr] + cost) {
                    dist[next] = dist[curr] + cost;
                    pq.push(pair<int, int>(dist[next], next));
                }
            }
        }
        return dist[to];
    }

    vector<vector<Edge>> nodes;
};

int m = 999999999;

void floyd(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int iter = 0; iter < n; iter++) {
        for (int here = 0; here < n; here++) {
            for (int there = 0; there < n; there++) {
                int cost = dist[here][iter] + dist[iter][there];
                if (dist[here][there] > cost)
                    dist[here][there] = cost;
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    --a;    --b;    --s;

    vector<vector<int>> dist(n);
    for (int i = 0; i < n; i++){
        dist[i] = vector<int>(n, m);
    }

    for (int i = 0; i < fares.size(); i++){
        dist[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        dist[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }

    floyd(dist);

    for (int i = 0; i < n; i++) {
        int sum = dist[i][a] + dist[i][b] + dist[s][i];
        if(sum > 0)
            m = min(m, dist[i][a] + dist[i][b] + dist[s][i]);
    }

    return m;
}

int main()
{
    std::cout << solution(6, 4, 6, 2, { {4, 1, 10},{3, 5, 24},{5, 6, 2},{3, 1, 41},{5, 1, 24},{4, 6, 50},{2, 4, 66},{2, 3, 22},{1, 6, 25 } });
}