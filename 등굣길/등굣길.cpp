#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> dp(n, vector<int>(m)), map(n, vector<int>(m));

    for (int i = 0; i < puddles.size(); i++) {
        map[puddles[i][1] - 1][puddles[i][0] - 1] = 1;
    }

    if (map[1][0] == 0) {
        dp[1][0] = 1;
    }
    if (map[0][1] == 0) {
        dp[0][1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                dp[i][j] = 0;
            }
            else {
                if (i - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
                }
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
                }
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    std::cout << solution(4, 3, { {2,2} });
}