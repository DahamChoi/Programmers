#include <iostream>
#include <vector>
using namespace std;

int next_tower(int num, int a) {
    return (num + a) >= 3 ? (num + a - 3) : num + a;
}

void next_one_step(vector<vector<int>>& answer, int index) {
    answer.push_back({ index + 1, next_tower(index, 2) + 1 });
    answer.push_back({ index + 1, next_tower(index, 1) + 1 });
    answer.push_back({ next_tower(index, 2) + 1, next_tower(index, 1) + 1 });
}

void next_two_step(vector<vector<int>>& answer, int index) {
    answer.push_back({ index + 1, next_tower(index, 1) + 1 });
    answer.push_back({ index + 1, next_tower(index, 2) + 1 });
    answer.push_back({ next_tower(index, 1) + 1, next_tower(index, 2) + 1 });
}

void tower_step(vector<vector<int>>& answer, int from, int to, int n) {
    int step = (to - from < 0) ? (to - from == -2) ? 1 : 2 : to - from;

    if (step == 2 && n == 2) {
        next_two_step(answer, from);
    }
    else if (step == 1 && n == 2) {
        next_one_step(answer, from);
    }
    else {
        tower_step(answer, from, next_tower(from, step == 2 ? 1 : 2), n - 1);
        answer.push_back({ from + 1, to + 1 });
        tower_step(answer, next_tower(from, step == 2 ? 1 : 2), to, n - 1);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    tower_step(answer, 0, 2, n);
    return answer;
}

int main() {
    vector<vector<int>> answer = solution(4);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i][0] << "," << answer[i][1] << endl;
    }
}

/*

(one step)
1,3
1,2
3,2

1,3

(one step)
2,1
2,3
1,3
------------------------------------

(two step)
1,2
1,3
2,3

+1
1,2

(two step)
3,1
3,2
1,2

+2
1,3

(two step)
2,3
2,1
3,1

+1
2,3

(two step)
1,2
1,3
2,3



*/