#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_safe(string s) {
    vector<char> stack(1, s.front());
    for (int i = 1; i < s.length(); i++) {
        if (stack.empty()) {
            stack.push_back(s[i]);
            continue;
        }
        char last = stack.back();
        if ((last == '[' && s[i] == ']') ||
            (last == '{' && s[i] == '}') ||
            (last == '(' && s[i] == ')')) {
            stack.pop_back();
        }
        else {
            stack.push_back(s[i]);
        }
    }
   
    return stack.empty();
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); i++) {
        string s1(s.begin() + i, s.end());
        string s2(s.begin(), s.begin() + i);
        if (is_safe(s1 + s2)) {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("}]()[{");
}