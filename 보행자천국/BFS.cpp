/*
using namespace std;

int MOD = 20170805;

struct queue_info {
    int x, y, direction;
};

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<bool>> visit(m, vector<bool>(n));
    queue<queue_info> q;
    q.push({ 0,1,0 });
    q.push({ 1,0,1 });
    visit[0][0] = true;

    while (!q.empty()) {
        queue_info p = q.front();
        q.pop();

        cout << p.x << "," << p.y << endl;

        if (p.x == n - 1 && p.y == m - 1) {
            ++answer;
            continue;
        }

        if ((city_map[p.y][p.x] == 2 && p.direction == 0) || city_map[p.y][p.x] == 0) {
            if (p.x + 1 < n && !visit[p.y][p.x + 1]) {
                //                visit[p.y][p.x + 1] = true;
                q.push({ p.x + 1, p.y, 0 });
            }
        }

        if ((city_map[p.y][p.x] == 2 && p.direction == 1) || city_map[p.y][p.x] == 0) {
            if (p.y + 1 < m && !visit[p.y + 1][p.x]) {
                //                visit[p.y + 1][p.x] = true;
                q.push({ p.x, p.y + 1, 1 });
            }
        }
    }

    return answer % MOD;
}
*/