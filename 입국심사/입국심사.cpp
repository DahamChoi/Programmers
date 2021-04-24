#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;

    double time_per_people = 0.0;
    for (int i = 0; i < times.size(); i++) {
        time_per_people += (1.0 / times[i]);
    }

    long long time_limit = ceil(n / time_per_people);

    int sum = 0;
    vector<int> counter(times.size());
    for (int i = 0; i < counter.size(); i++) {
        counter[i] = (time_limit / times[i]);
        sum += counter[i];
    }

    while (sum++ < n) {
        int min_index = 0;
        long long min_num = LLONG_MAX;
        for (int j = 0; j < times.size(); j++) {
            if ((counter[j] + 1) * times[j] < min_num) {
                min_num = (counter[j] + 1) * times[j];
                min_index = j;
            }
        }

        ++counter[min_index];
        answer = min_num;
    }

    return answer == LLONG_MAX ? time_limit : answer;
}

int main()
{
    std::cout << solution(6, { 7, 10 }) << endl;
}

/*
    long long cnt = 0, new_cnt = 0;
    double sum = 0.0;
    long long time = 0;
    while (sum < n) {
        double end_people = 0.0;
        for (int i = 0; i < div_times.size(); i++) {
            if (sum + div_times[i] * end_people + 1 < n) {
                end_people = div_times[i] * end_people + 1;
                time = cnt * times.back() + times[i];
            }
            else {
                if (i == 0) {
                    return time + (ceil(n - sum) * times[i]);
                }
                else {
                    while (sum < n) {
                        end_people = 0.0;
                        for (int j = 0; j <= i; j++) {
                            if (sum + div_times[j] * end_people + 1 < n) {
                                end_people = div_times[j] * end_people + 1;
                                time = (cnt * times.back()) + (new_cnt * times[i]) + times[j];
                            }
                            else {
                                cout << time << "," << n - (end_people + sum) << "," << time_per_people << endl;
                                return time + ceil((n - (end_people + sum)) / time_per_people);
                            }
                        }

                        sum += end_people;
                        ++new_cnt;
                    }
                }
            }
        }

        sum += end_people;
        ++cnt;
    }
    */