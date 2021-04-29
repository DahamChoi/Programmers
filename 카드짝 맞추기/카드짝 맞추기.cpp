#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> ctrl_move(vector<vector<int>>& board, int cursor_x, int cursor_y, int direction_x, int direction_y) {
    while (cursor_x + direction_x < board.size() && 
        cursor_x + direction_x >= 0 && 
        cursor_y + direction_y < board.size() && 
        cursor_y + direction_y >= 0 && 
        board[cursor_x][cursor_y] == 0) {
        cursor_x += direction_x;
        cursor_y += direction_y;
    }

    return { cursor_x, cursor_y };
}

int get_move_length(vector<vector<int>>& board, int cursor_x, int cursor_y, int goal_x, int goal_y) {
    int length = 0;
    int default_length_x = abs(cursor_x - goal_x);
    int default_length_y = abs(cursor_y - goal_y);

    pair<int,int> p1 = ctrl_move(board, cursor_x, cursor_y, cursor_x - goal_x < 0 ? 1 : -1, 0);
    pair<int,int> p2 = ctrl_move(board, p1.first, p1.second, 0, p1.second - goal_y < 0 ? 1 : -1);
    if (p2.first == goal_x && p2.second == goal_y) {
        return 2;
    }

    pair<int, int> p3 = ctrl_move(board, goal_x, cursor_y, 0, cursor_y - goal_y < 0 ? 1 : -1);
    if (p3.first == goal_x && p3.second == goal_y) {
        return default_length_x + 1;
    }

    pair<int, int> p4 = ctrl_move(board, cursor_x, goal_y, cursor_x - goal_x < 0 ? 1 : -1, 0);
    if (p4.first == goal_x && p4.second == goal_y) {
        return default_length_y + 1;
    }

    return default_length_x + default_length_y;
}

int remove_pair_card(vector<vector<int>>& board, int card_number, int cursor_x, int cursor_y, pair<int, int>& cursor_result) {
    vector<pair<int, int>> target_card_position;
    int first_move_x = 0, first_move_y = 0, max_length = INT_MAX, length = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == card_number) {
                target_card_position.push_back({ j, i });
                board[i][j] = 0;
            }
        }
    }

    int move_length_1 =
        get_move_length(board, cursor_x, cursor_y, target_card_position.front().first, target_card_position.front().second) +
        get_move_length(board, target_card_position.front().first, target_card_position.front().second, target_card_position.back().first, target_card_position.back().second);
    int move_length_2 =
        get_move_length(board, cursor_x, cursor_y, target_card_position.back().first, target_card_position.back().second) +
        get_move_length(board, target_card_position.back().first, target_card_position.back().second, target_card_position.front().first, target_card_position.front().second);

    if (move_length_1 < move_length_2) {
        cursor_result = { target_card_position.back().first, target_card_position.back().second };
        return move_length_1 + 2;
    }
    else {
        cursor_result = { target_card_position.front().first, target_card_position.front().second };
        return move_length_2 + 2;
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INT_MAX;

    vector<vector<int>> abc = { {1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1} };
    cout << get_move_length(abc, 0, 0, 3, 3) << endl;

    vector<int> card_numbers;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] != 0) {
                card_numbers.push_back(board[i][j]);
            }
        }
    }

    sort(card_numbers.begin(), card_numbers.end());
    card_numbers.erase(unique(card_numbers.begin(), card_numbers.end()), card_numbers.end());

    do {
        vector<vector<int>> temp_map = board;
        int sum_of_move = 0;
        pair<int, int> cursor = { c,r };
        for (int i = 0; i < card_numbers.size(); i++) {
            sum_of_move += remove_pair_card(temp_map, card_numbers[i], cursor.first, cursor.second, cursor);
        }
        answer = min(sum_of_move, answer);
    } while (next_permutation(card_numbers.begin(), card_numbers.end()));

    return answer;
}

int main()
{
    std::cout << solution({ {1, 0, 0, 3},{2, 0, 0, 0},{0, 0, 0, 2},{3, 0, 1, 0 }}, 1, 0);
}