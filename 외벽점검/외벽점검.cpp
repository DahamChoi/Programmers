#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int answer = INT_MAX;

void search_weak(vector<int>& weak, vector<int>& dist, int n, int original) {
    if (dist.empty() && !weak.empty()) {
        return;
    }

    if (weak.empty() || dist.empty()) {
        answer = min(answer, original - (int)dist.size());
        return;
    }

    int length = dist.back();
    for (int i = 0; i < weak.size(); i++) {
        int st = weak[i];
        int ed = (weak[i] + length) % n;

        vector<int> new_weak = weak;
        for (int j = 0; j < weak.size(); j++) {
            if (st < ed) {
                if (weak[j] >= st && weak[j] <= ed) {
                    new_weak.erase(find(new_weak.begin(), new_weak.end(), weak[j]));
                }
            }
            else {
                if (weak[j] >= st || weak[j] <= ed) {
                    new_weak.erase(find(new_weak.begin(), new_weak.end(), weak[j]));
                }
            }
        }

        dist.erase(dist.end() - 1);
        search_weak(new_weak, dist, n, original);
        dist.push_back(length);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    search_weak(weak, dist, n, (int)dist.size());
    return answer == INT_MAX ? -1 : answer;
}

int main()
{
    std::cout << solution(12, { 1, 5, 6, 10 }, { 1,2,3,4 });
}