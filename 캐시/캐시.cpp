#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache(cacheSize);
   
    for (int i = 0; i < cities.size(); i++) {
        std::transform(cities[i].begin(), cities[i].end(), cities[i].begin(), toupper);

        // Cache Hit
        bool hit = false;
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j] == cities[i]) {
                hit = true;
                ++answer;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                break;
            }
        }

        // Cache Miss
        if (!hit) {
            answer += 5;
            cache.push_back(cities[i]);
            if (cache.size() >= cacheSize) {
                cache.erase(cache.begin());
            }
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
}