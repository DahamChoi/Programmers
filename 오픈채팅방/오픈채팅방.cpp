#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct message {
    string action, uid;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_map;
    vector<message> user_info;

    for (int i = 0; i < record.size(); i++) {
        auto found1 = record[i].find(' ');
        string action = record[i].substr(0, found1);
        auto found2 = record[i].find(' ', found1 + 1);
        string uid = record[i].substr(found1 + 1, found2 - found1 - 1);
        string nickname = record[i].substr(found2 + 1, record[i].length() - found2);
        if (action == "Enter") {
            user_map[uid] = nickname;
            user_info.push_back({ action,uid });
        }
        else if (action == "Leave") {
            user_info.push_back({ action,uid });
        }
        else {
            user_map[uid] = nickname;
        }
    }

    for (int i = 0; i < user_info.size(); i++) {
        if (user_info[i].action == "Enter") {
            answer.push_back(user_map[user_info[i].uid] + "님이 들어왔습니다.");
        }
        else {
            answer.push_back(user_map[user_info[i].uid] + "님이 나갔습니다.");
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}