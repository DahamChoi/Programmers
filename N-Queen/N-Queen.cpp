#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
pair<int, int> dist[8] = { {-1,1},{-1,-1},{1,1},{1,-1},{0,1},{1,0},{0,-1},{-1,0} };

void search(vector<int> board, int n_queen, int index, int n) {
    if (n_queen >= n) {
        ++answer;
        return;
    }

    for (int k = 0; k < 8; k++) {
        int nx = (index % n);
        int ny = (index / n);
        while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            board[ny * n + nx] = 1;
            nx += dist[k].first;
            ny += dist[k].second;
        }
    }

    for (int i = n_queen * n; i < (n_queen + 1) * n; i++) {
        if (board[i] == 0) {
            search(board, n_queen + 1, i, n);
        }
    }
}

int solution(int n) {
    vector<int> board(n * n);
    answer = 0;

    for (int i = 0; i < n; i++) {
        search(board, 1, i, n);
    }

    return answer;
}

int main()
{
    for (int i = 1; i <= 12; i++) {
        std::cout << i << " : " << solution(i) << endl;
    }
}