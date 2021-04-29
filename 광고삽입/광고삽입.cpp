#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_second_by_string(string str) {
    return atoi(str.substr(0, 2).c_str()) * 60 * 60 +
        atoi(str.substr(3, 2).c_str()) * 60 +
        atoi(str.substr(6, 2).c_str());
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int adv_time_second = get_second_by_string(adv_time);
    int play_time_second = get_second_by_string(play_time);
    vector<unsigned long long> time_table(play_time_second + 1);

    for (auto& it : logs) {
        int st_time = get_second_by_string(it.substr(0, 8));
        int ed_time = get_second_by_string(it.substr(9, 8));
        for (int i = st_time + 1; i <= ed_time; i++) {
            ++time_table[i];
        }
    }

    for (int i = 1; i < time_table.size(); i++) {
        time_table[i] += time_table[i - 1];
    }

    unsigned long long max_time = 0, max_value = 0;
    for (int i = adv_time_second; i < time_table.size(); i++) {
        unsigned long long st_time = i - adv_time_second;
        if (time_table[i] - time_table[st_time] > max_value) {
            max_value = time_table[i] - time_table[st_time];
            max_time = st_time;
        }
    }

    if (max_time > play_time_second - adv_time_second) {
        max_time = play_time_second - adv_time_second;
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

    return hour_str + ":" + min_str + ":" + second_str;
}

int main()
{
    std::cout << solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });

    return 0;
}