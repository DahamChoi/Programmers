#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int number, x, y;
};

void pre(Node* node, vector<vector<int>>& answer) {
    if (node) {
        answer[0].emplace_back(node->number);
        pre(node->left, answer);
        pre(node->right, answer);
    }
}

void post(Node* node, vector<vector<int>>& answer) {
    if (node) {
        post(node->left, answer);
        post(node->right, answer);
        answer[1].emplace_back(node->number);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), 
        [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[1] == v2[1]) {
                return v1[0] < v2[0];
            }
            else {
                return v1[1] > v2[1];
            }
        });

    Node* root = new Node{ nullptr, nullptr, nullptr, nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1] };
    vector<Node*> nodeList = { root };
    int start = 1, end = 1;
    while (end < nodeinfo.size()) {
        int curY = nodeinfo[start][1];
        for (end = start + 1; end < nodeinfo.size(); end++) {
            if (nodeinfo[end][1] < curY) {
                break;
            }
        }

        int nodeIndex = 0;
        for (int i = start; i < end && nodeIndex < nodeList.size(); ) {
            Node* node = nodeList[nodeIndex];
            while (node->parent != nullptr) {
                if (node->x < nodeinfo[i][0]) {
                    if (node->parent->x - node->x > 0) {
                        if (!(nodeinfo[i][0] < node->parent->x)) {
                            break;
                        }
                    }
                    else {
                        if (!(nodeinfo[i][0] > node->parent->x)) {
                            break;
                        }
                    }
                }
                else {
                    if (node->parent->x - node->x > 0) {
                        if (!(nodeinfo[i][0] < node->parent->x)) {
                            break;
                        }
                    }
                    else {
                        if (!(nodeinfo[i][0] > node->parent->x)) {
                            break;
                        }
                    }
                }

                node = node->parent;
            }

            if (node == root) {
                if (nodeList[nodeIndex]->x < nodeinfo[i][0]) {
                    nodeList[nodeIndex]->right = new Node{ nullptr, nullptr, nodeList[nodeIndex], nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1] };
                    ++nodeIndex;
                    ++i;
                }
                else {
                    nodeList[nodeIndex]->left = new Node{ nullptr, nullptr, nodeList[nodeIndex], nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1] };
                    ++i;
                }
            }
            else {
                nodeIndex++;
            }
        }

        start = end;

        vector<Node*> temp = nodeList;
        nodeList.clear();
        for (auto it : temp) {
            if (it->left) {
                nodeList.push_back(it->left);
            }
            if (it->right) {
                nodeList.push_back(it->right);
            }
        }
    }

    pre(root, answer);
    post(root, answer);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = {
        {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}}
    };
    
    vector<vector<int>> answer = solution(nodeinfo);
    for (auto& it : answer) {
        for (auto& num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}