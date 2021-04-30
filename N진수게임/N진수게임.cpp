#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    map<int, char> number_map = { {0,'0'}, {1,'1'}, {2,'2'}, {3,'3'}, {4,'4'},
                     {5,'5'}, {6,'6'}, {7,'7'}, {8,'8'}, {9,'9'},
                     {10,'A'}, {11,'B'}, {12,'C'}, {13,'D'}, {14,'E'}, {15, 'F'} };

    string counter;
    for (int i = 0; i <= m * t; i++) {
        int radix = n, decimal = i;
        string number_str;
        while (decimal >= radix) {
            number_str += number_map[decimal % radix];
            decimal /= radix;
        }
        number_str += number_map[decimal % radix];
        reverse(number_str.begin(), number_str.end());
        counter += number_str;
    }

    for (int i = 0; i < t; i++) {
        int cnt = (m * i) + p - 1;
        answer += counter[cnt];
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}