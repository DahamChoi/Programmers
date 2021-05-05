#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int answer = INT_MAX;

void solution_function(int pos, int jump, int goal) {
    if (pos == goal) {
        answer = min(jump, answer);
        return;
    }

    if (pos > goal) {
        return;
    }

    cout << pos << endl;

    // Jump
    solution_function(pos + 1, jump + 1, goal);

    // Teleport
    solution_function(pos * 2, jump, goal);
}

int solution(int n) {
    solution_function(0, 0, n);
    return answer;
}

int main()
{
    int num = 5000, answer = 0;
    while (num > 0) {
        cout << num << endl;
        if (num % 2 == 1) {
            ++answer;
        }
        num /= 2;
    }

    cout << answer << endl;
}