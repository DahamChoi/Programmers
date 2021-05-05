#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string s) {
    int answer = 0, st = 0;
    vector<char> stack;
    stack.push_back(s.front());

    for (auto i = 1; i < s.length(); i++) {
        if (stack.empty()) {
            stack.push_back(s[i]);
            continue;
        }

        char back = stack.back();
        if (back == s[i]) {
            stack.pop_back();
        }
        else {
            stack.push_back(s[i]);
        }
    }

    return stack.empty();
}

int main()
{
    std::cout << solution("cdcd");
}