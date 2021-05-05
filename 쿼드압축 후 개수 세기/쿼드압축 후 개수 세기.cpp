#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);

void solution_function(vector<vector<int>>& arr, int w_st, int w_ed, int h_st, int h_ed) {
    int sum_of_size = 0, div_size = (w_ed - w_st);
    for (int i = h_st; i < h_ed; i++) {
        for (int j = w_st; j < w_ed; j++) {
            sum_of_size += arr[i][j];
        }
    }

    if (sum_of_size == 0 || sum_of_size == div_size * div_size) {
        ++answer[(sum_of_size == 0) ? 0 : 1];
    }
    else {
        if ((div_size /= 2) > 0) {
            solution_function(arr, w_st, w_st + div_size, h_st, h_st + div_size);
            solution_function(arr, w_st + div_size, w_st + div_size * 2, h_st, h_st + div_size);
            solution_function(arr, w_st, w_st + div_size, h_st + div_size, h_st + div_size * 2);
            solution_function(arr, w_st + div_size, w_st + div_size * 2, h_st + div_size, h_st + div_size * 2);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    solution_function(arr, 0, arr.size(), 0, arr.size());
    return answer;
}

int main()
{
    vector<int> answer = solution({ { 1,1,0,0 }, { 1,0,0,0 }, { 1,0,0,1 }, { 1,1,1,1 } });
    cout << answer[0] << "," << answer[1] << endl;
}