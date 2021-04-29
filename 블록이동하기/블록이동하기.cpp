#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct robot {
    int x1, x2, y1, y2;
};

int answer = INT_MAX;

bool is_rotate(vector<vector<int>>& board, robot& bot, int angle) {
    if (angle == 0) {
        int new_x = bot.x2 - 1;
        int new_y = bot.y2 + 1;
        if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board.size() &&
            board[new_y][new_x] == 0) {
            return true;
        }
    }
    else if (angle == 1) {
        int new_x = bot.x2 - 2;
        int new_y = bot.y2;
        if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board.size() &&
            board[new_y][new_x] == 0) {
            return true;
        }
    }
    else if (angle == 2) {
        int new_x = bot.x2 - 1;
        int new_y = bot.y2 - 1;
        if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board.size() &&
            board[new_y][new_x] == 0) {
            return true;
        }
    }

    return false;
}

robot rotate(robot& bot, int angle) {
    robot new_bot = bot;
    if (angle == 0) {
        --new_bot.x2;
        ++new_bot.y2;
    }
    else if (angle == 1) {
        new_bot.x2 -= 2;
    }
    else if (angle == 2) {
        --new_bot.x2;
        --new_bot.y2;
    }

    return new_bot;
}

void search(vector<vector<int>>& board, vector<vector<bool>> visit, robot bot, int depth) {
    if (bot.x1 < 0 || bot.x2 < 0 || bot.y1 < 0 || bot.y2 < 0 ||
        bot.x1 >= board.size() || bot.x2 >= board.size() || bot.y1 >= board.size() || bot.y2 >= board.size()) {
        return;
    }

    if (visit[bot.y1][bot.x1] && visit[bot.y2][bot.x2]) {
        return;
    }

    visit[bot.y1][bot.x1] = true;
    visit[bot.y2][bot.x2] = true;

    if ((bot.x1 == board.size() - 1 && bot.y1 == board.size() - 1) ||
        (bot.x2 == board.size() - 1 && bot.y2 == board.size() - 1)) {
        answer = min(answer, depth);
        return;
    }

    if (board[bot.x1][bot.y1] == 1 || board[bot.x2][bot.y2] == 1) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (is_rotate(board, bot, i)) {
            robot new_bot = rotate(bot, i);
            search(board, visit, { new_bot.x1 + 1, new_bot.x2 + 1, new_bot.y1, new_bot.y2 }, depth + 1);
            search(board, visit, { new_bot.x1 - 1, new_bot.x2 - 1, new_bot.y1, new_bot.y2 }, depth + 1);
            search(board, visit, { new_bot.x1, new_bot.x2, new_bot.y1 + 1, new_bot.y2 + 1 }, depth + 1);
            search(board, visit, { new_bot.x1, new_bot.x2, new_bot.y1 - 1, new_bot.y2 - 1 }, depth + 1);
        }
    }

    search(board, visit, { bot.x1 + 1, bot.x2 + 1, bot.y1, bot.y2 }, depth + 1);
    search(board, visit, { bot.x1 - 1, bot.x2 - 1, bot.y1, bot.y2 }, depth + 1);
    search(board, visit, { bot.x1, bot.x2, bot.y1 + 1, bot.y2 + 1 }, depth + 1);
    search(board, visit, { bot.x1, bot.x2, bot.y1 - 1, bot.y2 - 1 }, depth + 1);
}

int solution(vector<vector<int>> board) {
    vector<vector<bool>> visit(board.size(), vector<bool>(board.size()));
    search(board, visit, { 0,1,0,0 }, 0);

    return answer;
}

int main()
{
    std::cout << solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });
}