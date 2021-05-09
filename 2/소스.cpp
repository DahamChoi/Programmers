/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value, index;
    vector<int> edges;
};

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;

    vector<Node*> graph(a.size());
    for (int i = 0; i < graph.size(); i++) {
        graph[i] = new Node();
        graph[i]->value = a[i];
        graph[i]->index = i;
    }

    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]]->edges.push_back(edges[i][1]);
        graph[edges[i][1]]->edges.push_back(edges[i][0]);
    }

    Node* curNode = graph[0];
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i]->edges.size() == 1) {
            curNode = graph[i];
            break;
        }
    }

    while (true) {
        if (curNode->edges.size() == 1) {
            if (curNode->value < 0) {
                answer += -curNode->value;
                graph[curNode->edges[0]]->value -= abs(curNode->value);
                curNode->value = 0;
            }
            else if (curNode->value > 0) {
                answer += curNode->value;
                graph[curNode->edges[0]]->value += abs(curNode->value);
                curNode->value = 0;
            }

            graph[curNode->edges[0]]->edges.erase(find(graph[curNode->edges[0]]->edges.begin(), graph[curNode->edges[0]]->edges.end(), curNode->index));
            curNode = graph[curNode->edges[0]];
        }
        else if (curNode->edges.size() > 1) {
            if (graph[curNode->edges[0]]->edges.size() < graph[curNode->edges[1]]->edges.size()) {
                curNode = graph[curNode->edges[0]];
            }
            else {
                curNode = graph[curNode->edges[1]];
            }
        }
        else {
            break;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ -5, 0, 2, 1, 2 }, { {0,1},{3,4},{2,3},{0,3} });
}
*/