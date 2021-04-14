#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string makeString(int time) {
    int hour = time / 60;
    int minute = time % 60;
    string hourString;
    string minuteString;

    if (hour < 10) {
        hourString = "0" + to_string(hour);
    }
    else {
        hourString = to_string(hour);
    }

    if (minute < 10) {
        minuteString = "0" + to_string(minute);
    }
    else {
        minuteString = to_string(minute);
    }

    return hourString + ":" + minuteString;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<int> timeTable;
    for (int i = 0; i < timetable.size(); i++) {
        timeTable.push_back(
            atoi(timetable[i].substr(0, 2).c_str()) * 60 +
            atoi(timetable[i].substr(3, 2).c_str()));
    }
    sort(timeTable.begin(), timeTable.end());

    int time, i, crew = 0;
    vector<vector<int>> bus(n);
    for (time = 540, i = 0; time < 540 + n * t; time += t, i++){
        for (int j = 0; j < m; j++) {
            if(crew < timeTable.size() && timeTable[crew] <= time)
                bus[i].push_back(timeTable[crew++]);
        }
    }

    if (bus[m - 1].size() < m) {
        return makeString(540 + i * t);
    }

    return makeString(bus.back()[m - 1] - 1);
}

int main()
{
    vector<string> timetable = { "09:10", "09:09", "08:00" };
    std::cout << solution(2,10,2,timetable);
}