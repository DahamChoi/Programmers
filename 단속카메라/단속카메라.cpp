#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, exec_car = 0;

    sort(routes.begin(), routes.end(), [](vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
        });

    vector<bool> visit(routes.size());
    for (int i = 0; i < routes.size(); i++) {
        if (visit[i]) {
            continue;
        }

        int camera_pos = routes[i][1];
        for (int j = 0; j < routes.size(); j++) {
            if (visit[j]) {
                continue;
            }

            if (camera_pos >= routes[j][0] && camera_pos <= routes[j][1]) {
                visit[j] = true;
            }
        }
        ++answer;
    }

    return answer;
}

int main()
{
    std::cout << solution({ { -20,15 }, { -14,-5 }, { -18,-13 }, { -5,-3 } });
}