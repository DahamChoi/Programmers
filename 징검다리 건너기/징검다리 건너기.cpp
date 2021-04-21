#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Node {
    int st, ed, si;
};

int solution(vector<int> stones, int k) {
    vector<int> sort_stones = stones;
    sort(sort_stones.begin(), sort_stones.end(), greater<>());
    sort_stones.erase(unique(sort_stones.begin(), sort_stones.end()), sort_stones.end());

    unordered_map<int, vector<int>> position;
    for (int i = 0; i < stones.size(); i++) {
        position[stones[i]].push_back(i);
    }

    for (auto it = position.begin(); it != position.end(); it++) {
        (*it).second.push_back(stones.size());
        (*it).second.insert((*it).second.begin(), -1);
    }

    vector<Node> stack;
    stack.push_back({ 0, (int)stones.size(), 0 });
    int min_num = sort_stones.front();

    while (!stack.empty()) {
        Node node = stack.back();
        stack.erase(stack.end() - 1);
        if (node.si >= sort_stones.size()) {
            int max_num = 0;
            for (int i = node.st; i < node.ed; i++) {
                max_num = max(max_num, stones[i]);
            }
            min_num = min(max_num, min_num);
            continue;
        }

        int prev_size = stack.size();
        vector<int>& pos_list = position[sort_stones[node.si]];
        for (int j = 1; j < pos_list.size() - 1; j++) {
            if (pos_list[j] >= node.st && pos_list[j] < node.ed) {
                if (pos_list[j - 1] <= node.st && pos_list[j] - node.st >= k) {
                    stack.push_back({ node.st, pos_list[j], node.si + 1 });
                }

                int st = pos_list[j] + 1;
                int ed = pos_list[j + 1] >= node.ed ? node.ed : pos_list[j + 1];
                if (ed - st >= k) {
                    stack.push_back({ st, ed, node.si + 1 });
                }
            }
        }

        if (stack.size() == prev_size) {
            stack.push_back({ node.st, node.ed, node.si + 1 });
        }
    }

    return min_num;
}

int main() {
    vector<int> stones = { 1, 1, 5, 1, 1, 5, 2, 2, 5, 2, 2 };

    std::cout << solution(stones, 3);
}