#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_succuess(vector<string>& board, int x, int y) {
    char block = board[y][x];
    for (int i = y; i < board.size() && i < y + 2; i++) {
        for (int j = x; j < board[i].size() && j < x + 2; j++) {
            if (board[i][j] != block || board[i][j] == 'X') {
                return false;
            }
        }
    }

    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int w = board.front().size(), h = board.size();

    bool checker = true;
    while (checker) {
        checker = false;
        vector<string> new_board = board;
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w - 1; j++) {
                if (is_succuess(board, j, i)) {
                    checker = true;
                    for (int k = i; k < i + 2; k++) {
                        for (int l = j; l < j + 2; l++) {
                            if (new_board[k][l] != 'X') {
                                new_board[k][l] = 'X';
                                ++answer;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (new_board[i][j] == 'X') {
                    for (int k = i; k >= 1; k--) {
                        int temp = new_board[k - 1][j];
                        new_board[k][j] = temp;
                        new_board[k - 1][j] = 'X';
                    }
                }
            }
        }

        board = new_board;
    }

    return answer;
}

int main()
{
    std::cout << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
}