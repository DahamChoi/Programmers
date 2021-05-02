#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

double factorial(double n) {
    if (n <= 1.0) {
        return 1;
    }

    return n * factorial(n - 1);
}

int solution(vector<vector<string>> clothes) {
    double answer = 0;

    for (long long i = 1; i < 30; i++) {
        answer += (factorial(30) / ((factorial(30 - i) * factorial(i))));
    }

    cout << (int)answer + 1;

    /*
    unordered_map<string, int> clothes_map;
    for (int i = 0; i < clothes.size(); i++) {
        ++clothes_map[clothes[i][1]];
    }

    vector<pair<string, int>> clothes_vector(clothes_map.begin(), clothes_map.end());
    int n = clothes_map.size();
    for (int r = 1; r <= n; r++) {
        vector<bool> cnd(n);
        for (int i = 0; i < r; i++) {
            cnd[i] = true;
        }

        do {
            int mult = 1;
            for (int i = 0; i < cnd.size(); i++) {
                if (cnd[i]) {
                    mult *= clothes_vector[i].second;
                }
            }
            answer += mult;
        } while (prev_permutation(cnd.begin(), cnd.end()));
    }
    */

    return answer;
}

int main(){
//    std::cout << answer;
    solution({ {} });

    return 0;
}