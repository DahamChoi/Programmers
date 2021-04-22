#include <iostream>
#include <string>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length() - answer; i++) {
        for (int j = s.length() - 1; j >= i; j--) {
            int left = i, right = j;
            while (left + 1 < right - 1 && s[left] == s[right]) {
                ++left;
                --right;
            }

            answer = max(answer, (j - i) + 1);
        }
    }

    return answer;
}

int main()
{
    std::cout << solution("abcdcba");
}