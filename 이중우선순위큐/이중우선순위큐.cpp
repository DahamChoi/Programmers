#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = { 0, 0 }, double_prioperty_queue;

    for (int i = 0; i < operations.size(); i++) {
        if (operations[i].front() == 'I') {
            int number = atoi(operations[i].substr(2, operations[i].size() - 2).c_str());
            double_prioperty_queue.push_back(number);
        }
        else if (operations[i].front() == 'D' && !double_prioperty_queue.empty()) {
            sort(double_prioperty_queue.begin(), double_prioperty_queue.end());

            if (operations[i][2] == '1') {
                double_prioperty_queue.pop_back();
            }
            else if (operations[i][2] == '-') {
                double_prioperty_queue.erase(double_prioperty_queue.begin());
            }
        }
    }

    sort(double_prioperty_queue.begin(), double_prioperty_queue.end());
    if (!double_prioperty_queue.empty()) {
        answer = { double_prioperty_queue.front(), double_prioperty_queue.back() };
    }

    return answer;
}

int main() {
    vector<int> answer = solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
    cout << answer[0] << "," << answer[1] << endl;
}