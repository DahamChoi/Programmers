#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct log_class {
    int st_second, ed_second;

    int get_time(int st, int ed) {
        int start = st_second, end = ed_second;
        if (ed_second > ed) {
            end = ed;
        }
        if (st_second < st) {
            start = st;
        }

        if (end - start > 0) {
            return end - start;
        }
        else {
            return 0;
        }
    }
};

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    if (play_time == adv_time) {
        return "00:00:00";
    }

    int play_time_second =
        atoi(string(adv_time.begin(), adv_time.begin() + 3).c_str()) * 60 * 60 +
        atoi(string(adv_time.begin() + 3, adv_time.begin() + 6).c_str()) * 60 +
        atoi(string(adv_time.begin() + 6, adv_time.begin() + 9).c_str());

    vector<log_class> log_list;
    for (auto& it : logs) {
        log_list.push_back({
            atoi(string(it.begin(),it.begin() + 3).c_str()) * 60 * 60 +
            atoi(string(it.begin() + 3, it.begin() + 6).c_str()) * 60 +
            atoi(string(it.begin() + 6, it.begin() + 9).c_str()),
            atoi(string(it.begin() + 9,it.begin() + 12).c_str()) * 60 * 60 +
            atoi(string(it.begin() + 12, it.begin() + 15).c_str()) * 60 +
            atoi(string(it.begin() + 15, it.begin() + 18).c_str())
            });
    }

    sort(log_list.begin(), log_list.end(), [](const log_class& c1, const log_class& c2) {
        return c1.st_second < c2.st_second;
        });

    int max_sum_of_time = 0, max_time = 0;
    for (int i = 0; i < log_list.size(); i++) {
        int adv_time = log_list[i].st_second;
        int adv_end_time = adv_time + play_time_second;
        int sum_of_time = 0;
        for (int j = 0; j < log_list.size(); j++) {
            if (log_list[j].st_second > adv_end_time) {
                break;
            }

            sum_of_time += log_list[j].get_time(adv_time, adv_end_time);
        }

        if (sum_of_time > max_sum_of_time) {
            max_sum_of_time = sum_of_time;
            max_time = adv_time;
        }
    }

    string hour_str = to_string(max_time / 60 / 60);
    if (hour_str.length() == 1) {
        hour_str.insert(hour_str.begin(), '0');
    }
    string min_str = to_string((max_time / 60) % 60);
    if (min_str.length() == 1) {
        min_str.insert(min_str.begin(), '0');
    }
    string second_str = to_string(max_time % 60);
    if (second_str.length() == 1) {
        second_str.insert(second_str.begin(), '0');
    }

    answer = hour_str + ":" + min_str + ":" + second_str;

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}