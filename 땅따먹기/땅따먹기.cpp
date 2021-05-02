#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct queue_info {
    int index, depth, sum;
};

int solution(vector<vector<int>> land) {
    vector<vector<int>> visit(land.size() + 2, vector<int>(4));
    int answer = 0;

    vector<vector<pair<int, int>>> sort_land(land.size() + 1, vector<pair<int, int>>(4));
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            sort_land[i][j].first = land[i][j];
            sort_land[i][j].second = j;
        }

        sort(sort_land[i].begin(), sort_land[i].end());
    }
    for(int i = 0; i < 4; i++){
        sort_land.back()[i].second = i;
    }

    queue<queue_info> queue;
    for (int i = 0; i < 4; i++) {
        queue.push({ i, 0, 0 });
    }

    while (!queue.empty()) {
        queue_info info = queue.front();
        queue.pop();

        if (info.depth >= land.size()) {
            answer = max(answer, info.sum);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int depth = info.depth + 1;
            if (i != info.index) {
                int sum = info.sum + land[info.depth][info.index];
                if (visit[depth][i] < sum) {
                    visit[depth][i] = sum;
                    for (int j = 0; j < 4; j++) {
                        visit[depth + 1][j] = max(visit[depth + 1][j], sum + sort_land[depth][1].first - 1);
                    }
                    queue.push({ i, depth, sum });
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> land(100000, vector<int>(4));
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 4; j++) {
            land[i][j] = rand() % 100 + 1;
        }
    }

    vector<vector<int>> sample = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };

    std::cout << solution(land);
}