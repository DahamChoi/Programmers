
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

std::string replace_all(const std::string& message, const std::string& pattern, const std::string& replace) {
    string result = message;
    auto pos = 0, offset = 0;
    while ((pos = result.find(pattern, offset)) != std::string::npos){
        result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
        offset = pos + replace.size();
    }

    return result;
}

vector<string> split_string(string s, string delimiter) {
    vector<string> result;

    auto pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        string token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    if (!s.empty()) {
        result.push_back(s);
    }

    return result;
}

void replace_melody(string& m) {
    m = replace_all(m, "C#", "Z");
    m = replace_all(m, "D#", "X");
    m = replace_all(m, "F#", "V");
    m = replace_all(m, "G#", "N");
    m = replace_all(m, "A#", "M");
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int last_answer_time = 0;

    replace_melody(m);

    for (int i = 0; i < musicinfos.size(); i++) {
        vector<string> split_list = split_string(musicinfos[i], ",");

        string start_time = split_list[0];
        string end_time = split_list[1];
        string music_title = split_list[2];
        string melody = split_list[3];

        replace_melody(melody);

        int st_min = atoi(split_list[0].substr(0, 2).c_str()) * 60 + atoi(split_list[0].substr(3, 2).c_str());
        int ed_min = atoi(split_list[1].substr(0, 2).c_str()) * 60 + atoi(split_list[1].substr(3, 2).c_str());
        int original_melody_time = ed_min - st_min;

        string loop_melody;
        for (int i = 0; i < original_melody_time / melody.length(); i++) {
            loop_melody += melody;
        }

        for (int i = 0; i < original_melody_time % melody.length(); i++) {
            loop_melody += melody[i];
        }

        if (loop_melody.find(m) != string::npos) {
            if (!answer.empty()) {
                if (original_melody_time > last_answer_time) {
                    answer = music_title;
                    last_answer_time = original_melody_time;
                }
            }
            else {
                answer = music_title;
                last_answer_time = original_melody_time;
            }
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("ABCDEFG", { { "12:00,12:14,HELLO,CDEFGAB" },{ "13:00,13:05,WORLD,ABCDEF" } });
}