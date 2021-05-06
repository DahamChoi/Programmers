#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned combination(unsigned n, unsigned k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    int result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int solution(int n) {
    int answer = 0;

    for (int i = n % 2; i <= n; i += 2) {
        answer += combination(i + ((n - i) / 2), i);
    }

    return answer;
}

int main()
{
    for (int i = 1; i < 10; i++) {
        std::cout << solution(i) << endl;
    }
}