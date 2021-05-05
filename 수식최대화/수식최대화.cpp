#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string s, string delimiter) {
    vector<string> result;

    auto pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        string token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    result.push_back(s);

    s.replace("A", s.begin());

    return result;
}

long long operator_function(long long num1, long long num2, char ch) {
    if (ch == '-') {
        return num1 - num2;
    }
    else if (ch == '*') {
        return num1 * num2;
    }
    else if (ch == '+') {
        return num1 + num2;
    }

    return 0;
}

long long solution(string expression) {
    long long answer = 0;

    vector<pair<long long, long long>> numbers;
    vector<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            int find = i - 1;
            while (find >= 0 && expression[find] >= '0' && expression[find] <= '9') {
                --find;
            }
            int num_1 = atoi(expression.substr(find + 1, 3).c_str());
            int num_2 = atoi(expression.substr(i + 1, 3).c_str());
            numbers.push_back({ num_1, num_2 });
            operators.push_back(expression[i]);
        }
    }

    vector<char> operator_list = operators;
    sort(operator_list.begin(), operator_list.end());
    operator_list.erase(unique(operator_list.begin(), operator_list.end()), operator_list.end());

    do {
        vector<pair<long long, long long>> copy_numbers = numbers;
        vector<char> copy_operators = operators;
        long long result = 0;
        for (int n = 0; n < operator_list.size(); n++) {
            for (int j = 0; j < copy_operators.size(); j++) {
                if (operator_list[n] == copy_operators[j]) {
                    result = operator_function(copy_numbers[j].first, copy_numbers[j].second, operator_list[n]);
                    if (j - 1 >= 0) {
                        copy_numbers[j - 1].second = result;
                    }
                    if (j + 1 < copy_numbers.size()) {
                        copy_numbers[j + 1].first = result;
                    }

                    copy_numbers.erase(copy_numbers.begin() + j);
                    j = copy_operators.end() - copy_operators.erase(copy_operators.begin() + j);
                }
            }
        }

        answer = max(abs(result), answer);
    } while (next_permutation(operator_list.begin(), operator_list.end()));

    return answer;
}

int main() 
{
    std::cout << solution("");
}