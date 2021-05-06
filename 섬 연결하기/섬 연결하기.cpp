#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void floyd(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int iter = 0; iter < n; iter++) {
        for (int here = 0; here < n; here++) {
            for (int there = 0; there < n; there++) {
                int cost = dist[here][iter] + dist[iter][there];
                if (dist[here][there] > cost)
                    dist[here][there] = cost;
            }
        }
    }
}

void dfs(vector<vector<int>>& map, vector<bool>& visit, int island) {
    for (int i = 0; i < map.size(); i++) {
        if (map[island][i] != 0 && !visit[i]) {
            visit[i] = true;
            dfs(map, visit, i);
        }
    }
}

bool is_safe(vector<bool>& visit) {
    for (int i = 0; i < visit.size(); i++) {
        if (!visit[i]) {
            return false;
        }
    }

    return true;
}

int solution(int n, vector<vector<int>> costs) {
    vector<vector<int>> original_map(n, vector<int>(n, INT_MAX / 2 - 1));
    vector<bool> original_visit(n);
    for (int i = 0; i < costs.size(); i++) {
        original_map[costs[i][0]][costs[i][1]] = costs[i][2];
        original_map[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    for (int i = 0; i < n; i++) {
        original_map[i][i] = 0;
    }

    floyd(original_map);

    for (auto it = costs.begin(); it != costs.end(); ) {
        if (original_map[(*it)[0]][(*it)[1]] != (*it)[2]) {
            it = costs.erase(it);
        }
        else {
            it++;
        }
    }

    sort(costs.begin(), costs.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
        });

    vector<bool> cnd(costs.size());
    for (int i = 0; i < n - 1; i++) {
        cnd[i] = true;
    }

    do {
        int num = 0;
        vector<vector<int>> map(n, vector<int>(n, 0));
        vector<bool> visit = original_visit;
        
        for (int i = 0; i < cnd.size(); i++){
            if (cnd[i]) {
                num += costs[i][2];
                map[costs[i][0]][costs[i][1]] = costs[i][2];
                map[costs[i][1]][costs[i][0]] = costs[i][2];
            }
        }

        dfs(map, visit, 0);

        if (is_safe(visit)) {
            return num;
        }
    } while (prev_permutation(cnd.begin(), cnd.end()));

    return -1;
}

/*

5 [[0, 1, 5], [1, 2, 3], [2, 3, 3], [3, 1, 2], [3, 0, 4], [2, 4, 6], [4, 0, 7]] 15
5 [[0, 1, 1], [3, 4, 1], [1, 2, 2], [2, 3, 4]] 8
4 [[0, 1, 5], [1, 2, 3], [2, 3, 3], [1, 3, 2], [0, 3, 4]] 9
5 [[0, 1, 1], [3, 1, 1], [0, 2, 2], [0, 3, 2], [0, 4, 100]] 104
6 [[0, 1, 5], [0, 3, 2], [0, 4, 3], [1, 4, 1], [3, 4, 10], [1, 2, 2], [2, 5, 3], [4, 5, 4]] 11
5 [[0, 1, 1], [2, 3, 1], [3, 4, 2], [1, 2, 2], [0, 4, 100]] 6
5 [[0, 1, 1], [0, 4, 5], [2, 4, 1], [2, 3, 1], [3, 4, 1]] 8
5 [[0, 1, 1], [0, 2, 2], [0, 3, 3], [0, 4, 4], [1, 3, 1]] 8

*/

int main()
{
    vector<vector<int>> costs = { {0,1,1,},{3,1,1},{0,2,2},{0,3,2},{0,4,100} };
    vector<vector<int>> costs2 = { {0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4},{2,4,6},{4,0,7} };
    std::cout << solution(5, costs);
}