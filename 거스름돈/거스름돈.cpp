#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < money.size(); i++) {
        for (int j = 1; j < dp.size(); j++) {
            if (money[i] == j || money[i] == 1) {
                dp[j] += 1;
            }
            else if (j >= money[i]) {
                dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
            }
        }
    }

    return dp[n];
}

int main()
{
    vector<int> money(10);
    for (int i = 0; i < money.size(); i++) {
        money[i] = i + 1;
    }
    std::cout << solution(5, { 1,2,5 });
}