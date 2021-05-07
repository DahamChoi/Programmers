#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int make_number_cnt(vector<pair<int, int>>& div_list, int number, int N, int depth) {
    if (number == 0) {
        return 0;
    }
    
    if (depth > 8) {
        return 32000;
    }

    int min_number = INT_MAX;
    for (int i = 0; i < div_list.size(); i++) {
        int cnt = div_list[i].second + make_number_cnt(div_list, abs(div_list[i].first - number), N, depth + div_list[i].second);
        min_number = min(cnt, min_number);
        if (div_list[i].first == number) {
            min_number = min(min_number, div_list[i].second);
        }
    }

    return min_number;
}

int solution(int N, int number) {
    vector<pair<int, int>> div_list = {
        {1, 2},
        {11, 3},
        {111, 4},
        {1111, 5},
        {11111, 6},
        {N, 1},
        {N + N * 10, 2},
        {N * 100 + N * 10 + N , 3},
        {N * 1000 + N * 100 + N * 10 + N, 4},
        {N * 10000 + N * 1000 + N * 100 + N * 10 + N, 5},
        {N - 1, 3}, 
        {N + 1, 3},
        {12, 4},
        {10, 4},
        {N + N, 2},
        {(N + N) * (N + N), 4}
    };

    int size = div_list.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (div_list[i].second + div_list[j].second <= 8 && div_list[i].first + div_list[j].first <= 32000) {
                div_list.push_back({ div_list[i].first + div_list[j].first , div_list[i].second + div_list[j].second });
            }

            if (div_list[i].second + div_list[j].second <= 8 && div_list[i].first * div_list[j].first <= 32000) {
                div_list.push_back({ div_list[i].first * div_list[j].first , div_list[i].second + div_list[j].second });
            }
        }
    }

    int answer = make_number_cnt(div_list, number, N, 0);
    return answer;
}

int main()
{
    std::cout << solution(5, 990);
}

/*
print(solution(5,12),4)
print(solution(2,11),3)
print(solution(5,5),1)
print(solution(5,10),2)
print(solution(5,31168),-1)
print(solution(1,1121),7)
print(solution(5,1010),7)
print(solution(3,4),3)
print(solution(5,5555),4)
print(solution(5,5550),5)
print(solution(5,20),3)
print(solution(5,30),3)
print(solution(6,65),4)
print(solution(5,2),3)
print(solution(5,4),3)
print(solution(1,1),1)
print(solution(1,11),2)
print(solution(1,111),3)
print(solution(1,1111),4)
print(solution(1,11111),5)
print(solution(7,7776),6)
print(solution(7,7784),5)
print(solution(2,22222),5)
print(solution(2,22223),7)
print(solution(2,22224),6)
print(solution(2,11111),6)
print(solution(2,11),3)
print(solution(2,111),4)
print(solution(2,1111),5)
print(solution(9,36),4)
print(solution(9,37),6)
print(solution(9,72),3)
print(solution(3,18),3)
print(solution(2,1),2)
print(solution(4,17),4)
*/