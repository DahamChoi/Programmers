#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = A.size(), i, j;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (i = 0, j = 0; i < A.size() && j < B.size();) {
        if (A[i] > B[j]) {
            ++j;
            --answer;
        }
        else if (A[i] == B[j]) {
            --answer;
            ++j;
        } else {
            ++i;
            ++j;
        }
    }

    return answer;
}

int main() {
    vector<int> A = { 5,1,3,7 };
    vector<int> B = { 2,2,6,8 };
    cout << solution(A, B);
}