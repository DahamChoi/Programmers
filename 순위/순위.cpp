#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void floyd(vector<vector<int>>& arr) {
    int n = arr.size() - 1;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> graph1(n + 1, vector<int>(n + 1, 1000));
    vector<vector<int>> graph2(n + 1, vector<int>(n + 1, 1000));
    for (int i = 0; i <= n; i++) {
        graph1[i][i] = 0;
        graph2[i][i] = 0;
    }

    vector<pair<vector<int>, vector<int>>> score(n + 1);
    for (int i = 0; i < results.size(); i++) {
        graph1[results[i][1]][results[i][0]] = 1;
        graph2[results[i][0]][results[i][1]] = 1;
    }

    floyd(graph1);      // 패배한 그래프
    floyd(graph2);      // 이긴 그래프

    vector<bool> answer_list(n + 1);
    for (int i = 1; i <= n; i++) {
        int sum_lose = 0, sum_win = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }

            if (graph1[i][j] != 1000) {
                ++sum_lose;
            }
            if (graph2[i][j] != 1000) {
                ++sum_win;
            }
        }

        if (sum_lose + sum_win == n - 1) {
            answer_list[i] = true;
            for (int j = 1; j <= n; j++) {
                if (graph2[i][j] == sum_win) {
                    answer_list[j] = true;
                }

                if (graph1[i][j] == sum_lose) {
                    answer_list[j] = true;
                }
            }
        }
    }

    for (int i = 0; i < answer_list.size(); i++) {
        if (answer_list[i]) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> results = { {4,3},{4,2},{3,2},{1,2},{2,5} };
    std::cout << solution(5, results);
}