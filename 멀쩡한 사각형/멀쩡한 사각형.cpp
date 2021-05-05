#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int euclidean(int n, int m) {
    vector<int> answer;

    // Euclidean
    int a = n, b = m;
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        a = a % b;

        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    return b;
}

long long solution(int w, int h) {
    long long a = euclidean(w, h);
    long long min_1 = min(w / a, h / a), max_1 = max(w / a, h / a);
    long long b = min_1 * max_1;

    return w * (long long)h - a * (b - (min_1 - 1) * (max_1 - 1));
}

int main()
{
    std::cout << solution(8, 12);
}

/*
vector<int> solution(int n, int m) {
    vector<int> answer;

    // Euclidean
    int a = n, b = m;
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        a = a % b;

        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    return { b, n * m / b };
}
*/

/*
long long solution(int w, int h) {
    long long answer = w * (long long)h;
    double a = (w < h) ? (h / (double)w) : (w / (double)h);
    return answer - min(w, h) * ceil(a);
    return w * (long long)h - (long long)min(w,h) * ceil(max(h / (double)w, w / (double)h));
}
*/