/*
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<Node*> winner, losser;
    int depth, index;
};

bool search_winner_node(vector<Node*>& graph, int index, int value) {
    bool answer = false;
    for (int i = 0; i < graph[index - 1]->winner.size(); i++) {
        if (graph[index - 1]->winner[i]->index == value) {
            return true;
        }
        else {
            answer |= search_winner_node(graph, graph[index - 1]->winner[i]->index, value);
        }
    }

    return answer;
}

bool search_losser_node(vector<Node*>& graph, int index, int value) {
    bool answer = false;
    for (int i = 0; i < graph[index - 1]->losser.size(); i++) {
        if (graph[index - 1]->losser[i]->index == value) {
            return true;
        }
        else {
            answer |= search_losser_node(graph, graph[index - 1]->losser[i]->index, value);
        }
    }

    return answer;
}

int sum_of_winner(vector<Node*>& graph, int index) {
    int sum = graph[index - 1]->winner.size();
    for (int i = 0; i < graph[index - 1]->winner.size(); i++) {
        sum += sum_of_winner(graph, graph[index - 1]->winner[i]->index);
    }

    return sum;
}

int sum_of_losser(vector<Node*>& graph, int index) {
    int sum = graph[index - 1]->losser.size();
    for (int i = 0; i < graph[index - 1]->losser.size(); i++) {
        sum += sum_of_losser(graph, graph[index - 1]->losser[i]->index);
    }

    return sum;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<Node*> graph(n);
    for (int i = 0; i < graph.size(); i++) {
        graph[i] = new Node{ vector<Node*>(), vector<Node*>(), 0, i + 1 };
    }

    for (int i = 0; i < results.size(); i++) {
        graph[results[i][1] - 1]->winner.push_back(graph[results[i][0] - 1]);
        graph[results[i][0] - 1]->losser.push_back(graph[results[i][1] - 1]);
    }

    for (int i = 0; i < graph.size(); i++) {
        vector<Node*> remove_value;
        for (int j = 0; j < graph[i]->winner.size(); j++) {
            for (int k = 0; k < graph[i]->winner.size(); k++) {
                if (j == k) {
                    continue;
                }

                if (search_winner_node(graph, graph[i]->winner[k]->index, graph[i]->winner[j]->index)) {
                    remove_value.push_back(graph[i]->winner[j]);
                }
            }
        }

        remove_value.erase(unique(remove_value.begin(), remove_value.end()), remove_value.end());
        for (int j = 0; j < remove_value.size(); j++) {
            remove_value[j]->losser.erase(find(remove_value[j]->losser.begin(), remove_value[j]->losser.end(), graph[i]));
            graph[i]->winner.erase(find(graph[i]->winner.begin(), graph[i]->winner.end(), remove_value[j]));
        }

        remove_value.clear();
        for (int j = 0; j < graph[i]->losser.size(); j++) {
            for (int k = 0; k < graph[i]->losser.size(); k++) {
                if (j == k) {
                    continue;
                }

                if (search_losser_node(graph, graph[i]->losser[k]->index, graph[i]->losser[j]->index)) {
                    remove_value.push_back(graph[i]->losser[j]);
                }
            }
        }

        remove_value.erase(unique(remove_value.begin(), remove_value.end()), remove_value.end());
        for (int j = 0; j < remove_value.size(); j++) {
            remove_value[j]->winner.erase(find(remove_value[j]->winner.begin(), remove_value[j]->winner.end(), graph[i]));
            graph[i]->losser.erase(find(graph[i]->losser.begin(), graph[i]->losser.end(), remove_value[j]));
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        if (sum_of_winner(graph, i + 1) + sum_of_losser(graph, i + 1) == n - 1) {
            ++answer;
        }
    }

    return answer;
}

*/