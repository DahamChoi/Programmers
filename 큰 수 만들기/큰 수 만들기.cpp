#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer, sort_number = number;
    int st = 0, ed = k - 1;
    
    while (++ed < number.length()) {
        int max_num = 0, max_index = st;
        for (int i = st; i <= ed; i++) {
            if (number[i] > max_num) {
                max_num = number[i];
                max_index = i;
            }
        }

        answer += number[max_index];
        st = max_index + 1;
    }

    return answer;
}

int main()
{
    std::cout << solution("4177252841", 4);
}