#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct robot {
    int x1, x2, y1, y2, orientation;

    // x1, y1기준으로 90도:-90도 회전 - x2, y2 기준으로 90도:-90도 회전
    bool can_rotate(vector<vector<int>>& board, int type) {
        // 가로
        if (orientation == 0) {
            if (type == 0) {
                if (y1 + 1 < board.size() && x1 + 1 < board.size() && 
                    board[y1 + 1][x1] == 0 && board[y1 + 1][x1 + 1] == 0) {
                    return true;
                }
            }
            else if (type == 1) {
                if (y1 - 1 >= 0 && x1 + 1 < board.size() && 
                    board[y1 - 1][x1] == 0 && board[y1 - 1][x1 + 1] == 0) {
                    return true;
                }
            }
            else if (type == 2) {
                if (y1 - 1 >= 0 &&
                    board[y1 - 1][x1] == 0 && board[y1 - 1][x2] == 0) {
                    return true;
                }
            }
            else if (type == 3) {
                if (y1 + 1 < board.size() &&
                    board[y1 + 1][x1] == 0 && board[y1 + 1][x2] == 0) {
                    return true;
                }
            }
        }
        // 세로
        else {
            if (type == 0) {
                if (x1 - 1 >= 0 && y1 + 1 < board.size() &&
                    board[y1][x1 - 1] == 0 && board[y1 + 1][x1 - 1] == 0) {
                    return true;
                }
            }
            else if (type == 1) {
                if (x1 + 1 < board.size() && y1 + 1 < board.size() && 
                    board[y1][x1 + 1] == 0 && board[y1 + 1][x1 + 1] == 0) {
                    return true;
                }
            }
            else if (type == 2) {
                if (x1 + 1 < board.size() && y1 + 1 < board.size() &&
                    board[y1][x1 + 1] == 0 && board[y1 + 1][x1 + 1] == 0) {
                    return true;
                }
            }
            else if (type == 3) {
                if (x1 - 1 >= 0 && y1 + 1 < board.size() &&
                    board[y1][x1 - 1] == 0 && board[y1 + 1][x1 - 1] == 0) {
                    return true;
                }
            }
        }

        return false;
    }

    bool is_out_of_range(vector<vector<int>>& board) {
        return (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= board.size() || x2 >= board.size() || y1 >= board.size() || y2 >= board.size());
    }

    bool is_block_map(vector<vector<int>>& board) {
        return (board[y1][x1] == 1 || board[y2][x2] == 1);
    }

    bool is_goal(vector<vector<int>>& board) {
        return (x1 == board.size() - 1 && y1 == board.size() - 1) || (x2 == board.size() - 1 && y2 == board.size() - 1);
    }

    bool is_visit(vector<vector<vector<bool>>>& visit) {
        return (visit[y1][x1][orientation] && visit[y2][x2][orientation]);
    }

    void set_visit(vector<vector<vector<bool>>>& visit) {
        visit[y1][x1][orientation] = true;
        visit[y2][x2][orientation] = true;
    }

    robot rotate_robot(robot& bot, int type) {
        // 가로
        if (orientation == 0) {
            if (type == 0) {
                return { bot.x1, bot.x1, bot.y1, bot.y1 + 1, 1 };
            }
            else if (type == 1) {
                return { bot.x1, bot.x1, bot.y1 - 1, bot.y1, 1 };
            }
            else if (type == 2) {
                return { bot.x2, bot.x2, bot.y1 - 1, bot.y1, 1 };
            }
            else if (type == 3) {
                return { bot.x2, bot.x2, bot.y1, bot.y1 + 1, 1 };
            }
        }
        // 세로
        else {
            if (type == 0) {
                return { bot.x1 - 1, bot.x1, bot.y1, bot.y1, 0 };
            }
            else if (type == 1) {
                return { bot.x1, bot.x1+ 1, bot.y1, bot.y1, 0 };
            }
            else if (type == 2) {
                return { bot.x1, bot.x1 + 1, bot.y2, bot.y2, 0 };
            }
            else if (type == 3) {
                return { bot.x1 - 1, bot.x1, bot.y2, bot.y2, 0 };
            }
        }
    }
};

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;

    vector<vector<vector<bool>>> visit(board.size(), vector<vector<bool>>(board.size(), vector<bool>(2)));
    visit[0][0][0] = true;
    visit[0][1][0] = true;

    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    queue<pair<robot, int>> stack;
    stack.push({ { 0,1,0,0,0 }, 0 });

    while (!stack.empty()) {
        pair<robot, int> p = stack.front();
        stack.pop();

        if (p.second >= answer) {
            continue;
        }

        if (p.first.is_goal(board)) {
            answer = min(p.second, answer);
            continue;
        }

        cout << p.second << endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (i == p.first.y1 && j == p.first.x1) {
                    cout << "X" << " ";
                }
                else if (i == p.first.y2 && j == p.first.x2) {
                    cout << "Y" << " ";
                }
                else {
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < 4; i++) {
            robot new_bot = { p.first.x1 + dx[i], p.first.x2 + dx[i], p.first.y1 + dy[i], p.first.y2 + dy[i], p.first.orientation };
            if (!new_bot.is_out_of_range(board) && !new_bot.is_block_map(board) && !new_bot.is_visit(visit)) {
                new_bot.set_visit(visit);
                stack.push({ new_bot, p.second + 1 });
            }
        }

        for (int i = 0; i < 4; i++) {
            if (p.first.can_rotate(board, i)) {
                robot new_bot = p.first.rotate_robot(p.first, i);
                if (!new_bot.is_out_of_range(board) && !new_bot.is_block_map(board) && !new_bot.is_visit(visit)) {
                    new_bot.set_visit(visit);
                    stack.push({ new_bot, p.second + 1 });
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> map = { {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} };
    vector<vector<int>> big_map(5, vector<int>(5));
    vector<vector<int>> map_2 = { {{0, 0, 0, 0, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1, 0, 0},{1, 1, 1, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 1, 1, 0, 0},{0, 1, 1, 1, 1, 1, 1, 1, 1},{0, 0, 1, 1, 1, 1, 1, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0},{1, 1, 1, 1, 1, 1, 1, 1, 0}} };
    std::cout << solution(map_2);
}