#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    int number = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = number++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        int y1 = queries[i][0] - 1;
        int x1 = queries[i][1] - 1;
        int y2 = queries[i][2] - 1;
        int x2 = queries[i][3] - 1;
        int min_num = INT_MAX;

        vector<vector<int>> original_matrix = matrix;

        // 우측 회전
        for (int j = x1 + 1; j <= x2; j++) {
            matrix[y1][j] = original_matrix[y1][j - 1];
            min_num = min(min_num, matrix[y1][j]);
        }

        // 아래쪽 회전
        for (int j = y1 + 1; j <= y2; j++) {
            matrix[j][x2] = original_matrix[j - 1][x2];
            min_num = min(min_num, matrix[j][x2]);
        }

        // 왼쪽 회전
        for (int j = x2 - 1; j >= x1; j--) {
            matrix[y2][j] = original_matrix[y2][j + 1];
            min_num = min(min_num, matrix[y2][j]);
        }

        // 위쪽 회전
        for (int j = y2 - 1; j >= y1; j--) {
            matrix[j][x1] = original_matrix[j + 1][x1];
            min_num = min(min_num, matrix[j][x1]);
        }

        /*
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        */

        answer.push_back(min_num);
    }

    return answer;
}

int main()
{
    vector<int> answer = solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}
