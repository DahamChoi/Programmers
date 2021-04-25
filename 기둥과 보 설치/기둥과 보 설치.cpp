#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int PILLAR = 0b01;
static const int BO = 0b10;

bool is_can_build(vector<vector<int>>& map) {
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map.size(); x++) {
            // 기둥
            if (map[y][x] & PILLAR) {
                bool b1 = false, b2 = false, b3 = false;
                if (y - 1 >= 0) {
                    b1 = (map[y - 1][x] & PILLAR);
                }
                if (x - 1 >= 0) {
                    b2 = (map[y][x - 1] & BO);
                }
                b3 = (map[y][x] & BO);

                if (!(y == 0 || b1 || b2 || b3)) {
                    return false;
                }
            }
            // 보
            if (map[y][x] & BO) {
                bool b1 = false, b2 = false, b3 = false;
                b1 = (map[y - 1][x] & PILLAR);

                if (x + 1 < map.size()) {
                    b2 = (map[y - 1][x + 1] & PILLAR);
                }

                if (x - 1 >= 0 && x + 1 < map.size()) {
                    b3 = ((map[y][x - 1] & BO) && (map[y][x + 1] & BO));
                }

                if (!(b1 || b2 || b3)) {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<int>> map(n + 1, vector<int>(n + 1));
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int frame = build_frame[i][2];
        int action = build_frame[i][3];

        // 설치
        if (action == 1) {
            int temp = map[y][x];
            map[y][x] += (frame == 0 ? PILLAR : BO);
            if (!is_can_build(map)) {
                map[y][x] = temp;
            }
            // 삭제
        }
        else if (action == 0) {
            int temp = map[y][x];
            map[y][x] -= (frame == 0 ? PILLAR : BO);
            if (!is_can_build(map)) {
                map[y][x] = temp;
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (map[i][j] & PILLAR) {
                answer.push_back({ j,i,0 });
            }

            if (map[i][j] & BO) {
                answer.push_back({ j,i,1 });
            }
        }
    }

    sort(answer.begin(), answer.end(), [](const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) {
            if (v1[1] == v2[1]) {
                return v1[2] < v2[2];
            }

            return v1[1] < v2[1];
        }

        return v1[0] < v2[0];
        });

    return answer;
}

int main()
{
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    solution(5, build_frame);
}