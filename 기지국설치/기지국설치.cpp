#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;

    vector<int> sink_range;
    int start = 1;

    for (int i = 0; i < stations.size(); i++) {
        sink_range.push_back(stations[i] - w - start);
        start = stations[i] + w + 1;
    }

    if (n - start + 1 > 0)
        sink_range.push_back(n - start + 1);

    for (int i = 0; i < sink_range.size(); i++) {
        answer += ceil(sink_range[i] / (float)(w * 2 + 1));
    }

    return answer;
}

int main() {
//    cout << solution(11, { 4,11 }, 1) << endl;
    cout << solution(16, { 9 }, 2) << endl;
}