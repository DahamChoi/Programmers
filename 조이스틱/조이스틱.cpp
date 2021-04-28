#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    char half_length = (('Z' - 'A') / 2) + 'A';

    for (int i = 0; i < name.length();) {
        int j = i;
        while (++j < name.length() && name[j] == 'A') {
            ;
        }
        
        if (name[i] > half_length) {
            answer += ('Z' - name[i] + 1);
        }
        else {
            answer += (name[i] - 'A');
        }

        if (j < name.length()) {
            if (j - i < i + name.length() - j) {
                answer += (j - i);
            }
            else {
                answer += (i + name.length() - j);
            }
        }

        cout << i << endl;
        i += (j - i);
    }

    return answer;
}

int main()
{
    std::cout << solution("JEROEN");
}