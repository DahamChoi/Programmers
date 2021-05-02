#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct condition_strucut {
    char friends_1, friends_2, condition;
    int interval;

    bool is_condition_safe(int i) {
        if (condition == '=') {
            return (interval == i);
        }
        else if (condition == '>') {
            return (interval < i);
        }
        else {
            return (interval > i);
        }
    }
};

int solution(int n, vector<string> data) {
    int answer = 0;

    vector<char> friend_list = { 'A','C','F','J','M','N','R','T' };
    sort(friend_list.begin(), friend_list.end());

    vector<condition_strucut> condition_list;
    for (int i = 0; i < data.size(); i++) {
        condition_list.push_back({ data[i][0], data[i][2], data[i][3], data[i][4] - '0' });
    }

    do {
        bool checker = true;
        for (int i = 0; i < condition_list.size(); i++) {
            int pos_1 = 0, pos_2 = 0;
            for (int j = 0; j < friend_list.size(); j++) {
                if (condition_list[i].friends_1 == friend_list[j]) {
                    pos_1 = j;
                }

                if (condition_list[i].friends_2 == friend_list[j]) {
                    pos_2 = j;
                }
            }

            if (!condition_list[i].is_condition_safe(abs(pos_1 - pos_2) - 1)) {
                checker = false;
                break;
            }
        }

        if (checker) {
            ++answer;
        }
    } while (next_permutation(friend_list.begin(), friend_list.end()));

    return answer;
}

int main()
{
    std::cout << solution(2, { "N~F=0", "R~T>2" });
}