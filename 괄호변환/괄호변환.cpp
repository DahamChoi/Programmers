#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution_function(string u, string v, string& vv) {
    int left_cnt = 0, right_cnt = 0;
    for (int i = 0; i < u.length(); i++) {
        if (u[i] == '(') {
            ++left_cnt;
        }
        else if (u[i] == ')') {
            ++right_cnt;
        }
    }

    cout << u << "," << v << endl;

    if (left_cnt == right_cnt && v.length() > 2) {
        auto it = find(v.begin(), v.end(), '(');
        v.erase(it);
        v.erase(find(it, v.end(), ')'));
        vv += "()";
        u += solution_function(v, "()", vv);
        return u;
    }
    else {
        string str;
        str.insert(str.begin(), '(');
        str += vv;
        str += ")";
        u.erase(u.begin());
        u.erase(u.end() - 1);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') {
                u[i] = ')';
            }
            else if (u[i] == ')') {
                u[i] = '(';
            }
        }
        str += u;
        return str;
    }
}

string solution(string p) {
    auto it = find(p.begin(), p.end(), '(');
    p.erase(it);
    p.erase(find(it, p.end(), ')'));
    string vv;
    return solution_function("()", p, vv);
}

int main()
{
    std::cout << solution("()))((()");
}