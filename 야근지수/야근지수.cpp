#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int, vector<int>> q;
    for (int i = 0; i < works.size(); i++) {
        q.push(works[i]);
    }

    while (n-- > 0) {
        int t = q.top();
        q.pop();
        q.push(t - 1);
    }

    while (!q.empty()) {
        answer += q.top() * q.top();
        q.pop();
    }

    return answer;
}

int main()
{
    std::cout << solution(4, { 4,3,3 });
}