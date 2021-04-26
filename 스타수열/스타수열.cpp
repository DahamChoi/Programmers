#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    for (int cnt = (a.size() - (a.size() % 2)) - 1; cnt >= 1; cnt -= 2) {
        vector<int> cnd(a.size(), 1);
        for (int i = 0; i <= cnt; i++) {
            cnd[i] = 0;
        }

        do {
            unordered_map<int, int> item_list;
            for (int i = 0; i < cnd.size(); i++) {
                if (cnd[i] == 0) {
                    ++item_list[a[i]];
                    cout << a[i] << " ";
                }
            }
            cout << endl;

            bool checker = false;
            for (auto it = item_list.begin(); it != item_list.end(); it++) {
                if (!(it->second == ((cnt + 1) / 2) || it->second == 1)) {
                    checker = true;
                    break;
                }
            }

            if (!checker) {
                return cnt + 1;
            }
        } while (next_permutation(cnd.begin(), cnd.end()));
    }

    return 0;
}

int main()
{
    std::cout << solution({ 0, 3, 3, 0, 7, 2, 0, 2, 2, 0 });
}