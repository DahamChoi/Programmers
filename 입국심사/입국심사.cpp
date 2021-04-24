#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    vector<double> people(times.size(), 1.0);
    vector<double> counter(times.size());

    for (int i = 0; i < times.size() - 1; i++) {
        people[i] = (times[i + 1] / (double)times[i]);
    }

    long long cnt = 0;
    double sum = 0.0;
    while (sum < n) {
        double end_people = 0.0;
        for (int i = 0; i < times.size(); i++) {
            if (sum + (end_people * people[i] + people[i]) < n) {
                end_people = ((end_people * people[i]) + people[i]);
            }
            else {
                int num = 0;
                while (sum + num++ < n)
                {
                    int min_index = 0;
                    long long min_num = LLONG_MAX;
                    for (int j = 0; j <= i; j++) {
                        if ((counter[j] + 1) * times[j] < min_num) {
                            min_num = (counter[j] + 1) * times[j];
                            min_index = j;
                        }
                    }

                    ++counter[min_index];
                    answer = min_num;
                }

                return answer;
            }
        }

        for (int i = 0; i < counter.size(); i++) {
            counter[i] += times.back() / times[i];
        }

        sum += end_people;
    }

    return answer;
}

int main()
{
    std::cout << solution(12, {1, 2, 3 });
}