#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) {
        return { -1 };
    }

    vector<int> answer(n, s / n);
    for (int i = answer.size() - 1; i >= answer.size() - (s % n); i--) {
        ++answer[i];
    }

    return answer;
}

int main() {
    vector<int> answer = solution(4, 9);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}
