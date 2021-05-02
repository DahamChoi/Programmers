#include <iostream>
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

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 1;
    Graph graph(N);

    for (int i = 0; i < road.size(); i++) {
        graph.nodes[road[i][0] - 1].push_back({ road[i][1] - 1, road[i][2] });
        graph.nodes[road[i][1] - 1].push_back({ road[i][0] - 1, road[i][2] });
    }

    for (int i = 1; i < N; i++) {
        if (graph.GetDistance(0, i) <= K) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> road = { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };
    vector<vector<int>> road_2 = { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} };
    std::cout << solution(5, road_2, 3);
}