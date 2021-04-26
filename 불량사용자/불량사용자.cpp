#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> select_id_list;

void search_banned(vector<vector<string>>& banned_id_list, vector<string>& select_id, int index) {
    for (int i = 0; i < banned_id_list[index].size(); i++) {
        bool checker = true;
        for (int j = 0; j < select_id.size(); j++) {
            if (banned_id_list[index][i] == select_id[j]) {
                checker = false;
                break;
            }
        }

        if (checker) {
            select_id.push_back(banned_id_list[index][i]);
            if (index == banned_id_list.size() - 1) {
                select_id_list.push_back(select_id);
            }
            else {
                search_banned(banned_id_list, select_id, index + 1);
            }
            select_id.erase(select_id.end() - 1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> banned_id_list(banned_id.size());

    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (banned_id[i].length() == user_id[j].length()) {
                bool checker = true;
                for (int k = 0; k < banned_id[i].length() && k < user_id[j].length(); k++) {
                    if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) {
                        checker = false;
                        break;
                    }
                }

                if (checker) {
                    banned_id_list[i].push_back(user_id[j]);
                }
            }
        }
    }

    vector<string> select_id;
    search_banned(banned_id_list, select_id, 0);

    for (int i = 0; i < select_id_list.size(); i++) {
        sort(select_id_list[i].begin(), select_id_list[i].end());
    }

    sort(select_id_list.begin(), select_id_list.end());
    select_id_list.erase(unique(select_id_list.begin(), select_id_list.end()), select_id_list.end());

    return select_id_list.size();
}

int main()
{
    std::cout << "Hello World!\n";
}