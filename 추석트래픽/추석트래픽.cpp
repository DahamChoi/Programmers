#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    vector<int> test(60 * 60 * 1000);
    for (int i = 0; i < lines.size(); i++) {
        int time =
            atoi(lines[i].substr(11, 2).c_str()) * 60 * 60 * 1000 +
            atoi(lines[i].substr(14, 2).c_str()) * 60 * 1000 +
            atoi(lines[i].substr(17, 2).c_str()) * 1000 +
            atoi(lines[i].substr(20, 3).c_str()) - 1;

        int num = 0;
        for (int j = 0; j < lines.size(); j++) {
            int ed_time =
                atoi(lines[j].substr(11, 2).c_str()) * 60 * 60 * 1000 +
                atoi(lines[j].substr(14, 2).c_str()) * 60 * 1000 +
                atoi(lines[j].substr(17, 2).c_str()) * 1000 +
                atoi(lines[j].substr(20, 3).c_str());
            int st_time = ed_time - (atof(lines[j].substr(24, lines[j].length() - 24).c_str()) * 1000);
            
            if ((st_time >= time && st_time < time + 1000) ||
                (ed_time >= time && ed_time < time + 1000) ||
                (st_time <= time && ed_time > time + 1000)) {
                ++num;
            }
        }
        answer = max(num, answer);
    }

    return answer;
}

int main()
{
    std::cout << solution(
        { 
            "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"
        }
    ); 
}