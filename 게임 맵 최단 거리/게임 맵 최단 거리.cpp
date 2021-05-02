#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct queue_info {
    int x, y, depth;
};

int solution(vector<vector<int>> maps) {
    int answer = INT_MAX, w = maps.front().size(), h = maps.size();

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    vector<vector<bool>> visit(h, vector<bool>(w));
    visit[0][0] = true;

    queue<queue_info> q;
    q.push({ 0,0,1 });

    while (!q.empty()) {
        queue_info info = q.front();
        q.pop();

        if (info.x == w - 1 && info.y == h - 1) {
            answer = min(answer, info.depth);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visit[ny][nx] && maps[ny][nx] == 1) {
                visit[ny][nx] = true;
                q.push({ nx,ny,info.depth + 1 });
            }
        }
    }

    return answer == INT_MAX ? -1 : answer;
}

int main()
{
    vector<vector<int>> map = { {1,0,1,1,1} ,{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} };
    std::cout << solution(map);
}