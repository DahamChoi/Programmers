#include <iostream>
#include <vector>

using namespace std;

int get_square_size(vector<vector<int>>& board, int y, int x, int default_size, int min_num, vector<vector<int>>& dp_w, vector<vector<int>>& dp_h) {
    int result = default_size;
    while (result <= min_num && y + result <= board.size() && x + result <= board.front().size()) {
        for (int i = y; i < y + result; i++) {
            if (dp_w[i][x + result - 1] < result) {
                return result - 1;
            }
        }

        for (int j = x; j < x + result; j++) {
            if (dp_h[y + result - 1][j] < result) {
                return result - 1;
            }
        }

        ++result;
    }

    return (result == default_size) ? result : result - 1;
}

int solution(vector<vector<int>> board) {
    int h = board.size(), w = board.front().size();
    int answer = 1;

    vector<vector<int>> dp_w = board, dp_h = board;
    for (int i = 0; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (board[i][j]) {
                dp_w[i][j] += dp_w[i][j - 1];
            }
        }
    }

    for (int i = 1; i < h; i
        ++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 1) {
                dp_h[i][j] += dp_h[i - 1][j];
            }
        }
    }
    
    for (int i = 0; i <= h - answer; i++) {
        for (int j = 0; j <= w - answer; j++) {
            if (board[i][j] == 1) {
                answer = max(answer, get_square_size(board, i, j, answer, min(w, h), dp_w, dp_h));
            }
        }
    }

    return answer * answer;
}

int main()
{
    vector<vector<int>> board1 = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
    vector<vector<int>> board2 = { {0,0,1,1},{1,1,1,1} };
    vector<vector<int>> board3 = { {0,1,1,0,1},{0,1,1,0,1},{0,0,0,0,1},{0,0,0,0,1},{0,0,0,0,1} };
    vector<vector<int>> big_map(1000, vector<int>(1000));
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            big_map[i][j] = 1;
        }
    }
    std::cout << solution(big_map);
}



/*


int solution(vector<vector<int>> board) {
    int h = board.size(), w = board.front().size();
    int answer = 1, cnt = 1, result = 0;

    while (min(h,w) >= cnt) {
        for (int k = 0; k <= h - answer; k++) {
            for (int l = 0; l <= w - answer; l++) {
                int prev_answer = answer;
                while (h > k + answer && w > l + answer) {
                    int sum_of_map = 0;
                    for (int i = k; i < k + answer; i++) {
                        for (int j = l; j < l + answer; j++) {
                            sum_of_map += board[i][j];
                        }
                    }

                    if (sum_of_map == answer * answer) {
                        ++answer;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        ++cnt;
    }

    return answer * answer;
}

*/