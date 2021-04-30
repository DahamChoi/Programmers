#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool is_unique(vector<vector<string>>& relation, vector<bool> select) {
    map<vector<string>, int> list;
    for (int i = 0; i < relation.size(); i++) {
        vector<string> temp;
        for (int j = 0; j < select.size(); j++) {
            if (select[j]) {
                temp.push_back(relation[i][j]);
            }
        }

        if (list[temp]++ > 0) {
            return false;
        }
    }

    return true;
}

vector<bool> and_result(vector<bool>& c1, vector<bool>& c2) {
    vector<bool> result(c1.size());
    for (int i = 0; i < c1.size(); i++) {
        result[i] = c1[i] & c2[i];
    }

    return result;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    int column = relation.front().size();
    int row = relation.size();

    vector<vector<bool>> cnd_list;

    for (int i = 1; i <= column; i++) {
        vector<bool> cnd(column);
        for (int j = 0; j < i; j++) {
            cnd[j] = true;
        }

        do {
            if (is_unique(relation, cnd)) {
                bool checker = false;
                for (int i = 0; i < cnd_list.size(); i++) {
                    if (and_result(cnd_list[i], cnd) == cnd_list[i]) {
                        checker = true;
                    }
                }
                if (!checker) {
                    ++answer;
                }
                cnd_list.push_back(cnd);
            }
        } while (prev_permutation(cnd.begin(), cnd.end()));
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}