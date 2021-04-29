#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    dp[1][1][0] = dp[1][1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (city_map[i - 1][j - 1] == 0) {
                dp[i][j][0] += (dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD;
                dp[i][j][1] += (dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
            else {
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i][j - 1][1];
            }
        }
    }

    return dp[m][n][0];
}

int main()
{
    std::cout << solution(3, 6, { {0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} });
}