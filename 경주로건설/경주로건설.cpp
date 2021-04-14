#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Q {
	int x, y, straight, curve, direction;
};

int solution(vector<vector<int>> board) {

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int size = board.size();
	int answer = 99999999;
	
	for (int k = 0; k < 2; k++) {
		vector<vector<vector<bool>>> visit(size, vector<vector<bool>>(size, vector<bool>(size * size)));
		queue<Q> q;
		q.push({ 0,0,0,0,k });
		visit[0][0][0] = true;

		while (!q.empty()) {
			Q t = q.front();
			q.pop();

			if (t.x == size - 1 && t.y == size - 1) {
				answer = min(t.curve * 500 + t.straight * 100, answer);
			}

			for (int i = 0; i < 4; i++) {
				int ny = (t.y + dy[i]);
				int nx = (t.x + dx[i]);
				int curve_new = ((i == t.direction) ? t.curve : t.curve + 1);
				if (ny >= 0 && ny < size && nx >= 0 && nx < size && curve_new < size) {
					if (!visit[ny][nx][curve_new] && board[ny][nx] == 0) {
						visit[ny][nx][curve_new] = true;
						q.push({ nx, ny, t.straight + 1, curve_new, i });
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0}
	};
	cout << solution(board);
	return 0;
}