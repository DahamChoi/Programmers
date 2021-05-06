#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, size = computers.size();
    
    vector<bool> visit(size);
    for (int k = 0; k < size; k++) {
        if (!visit[k]) {
            queue<int> q;
            q.push(k);
            while (!q.empty()) {
                int t = q.front();
                q.pop();

                for (int i = 0; i < size; i++) {
                    if (!visit[i] && i != t && computers[t][i] == 1) {
                        visit[i] = true;
                        q.push(i);
                    }
                }
            }
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(3, { {1,1,0},{1,1,1},{0,1,1} });
}