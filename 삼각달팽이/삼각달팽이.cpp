#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int number = 1, max_number = 0;
    int down_index = 0, down_cnt = n, foward_index = n - 1, foward_cnt = n - 1, up_index = n - 2, up_cnt = n - 2;

    vector<int> snail_index(n);
    vector<vector<int>> snail(n);
    for (int i = 1; i <= n; i++) {
        snail[i - 1] = vector<int>(i);
        max_number += i;
    }

    while (true) {
        // 내려가기
        for (int i = down_index; i < down_index + down_cnt; i++) {
            snail[i][snail_index[i]++] = number++;
        }

        down_index += 2;
        down_cnt -= 3;

        if (number > max_number) {
            break;
        }

        // 앞으로 가기
        for (int i = snail_index[foward_index]; i < snail_index[foward_index] + foward_cnt; i++) {
            snail[foward_index][i] = number++;
        }

        --foward_index;
        foward_cnt -= 3;

        if (number > max_number) {
            break;
        }

        // 올라가기
        for (int i = up_index; i > up_index - up_cnt; i--) {
            snail[i][snail[i].size() - snail_index[i]] = number++;
        }

        --up_index;
        up_cnt -= 3;

        if (number > max_number) {
            break;
        }
    }

    for (int i = 0; i < snail.size(); i++) {
        for (int j = 0; j < snail[i].size(); j++) {
            answer.push_back(snail[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<int> answer = solution(10);

    return 0;
}