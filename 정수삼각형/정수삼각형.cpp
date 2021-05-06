#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, h = triangle.size();

    vector<vector<int>> dp(h, vector<int>(h));
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j - 1 >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
        }
    }

    for (int i = 0; i < h; i++) {
        answer = max(answer, dp.back()[i]);
    }

    return answer;
}

int main()
{
    std::cout << solution({ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} });
}