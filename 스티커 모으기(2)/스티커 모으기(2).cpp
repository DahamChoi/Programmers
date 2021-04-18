#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int max_1, max_2, max_3, max_4;
};

int solution(vector<int> sticker) {
    int answer = 0, lastnumber = sticker.back();
    int shink_sticker = 5 - (sticker.size() % 5);

    for (int i = 0; i < shink_sticker; i++) {
        sticker.push_back(0);
    }

    for (int n = 0; n < 2; n++) {
        if (n == 0) {
            sticker[sticker.size() - shink_sticker - 1] = 0;
        }
        else {
            sticker[0] = 0;
            sticker[sticker.size() - shink_sticker - 1] = lastnumber;
        }

        vector<Node> nodelist;
        for (int i = 0; i < sticker.size() - 4; i += 5) {
            nodelist.push_back({
                max(max(sticker[i] + sticker[i + 2], sticker[i] + sticker[i + 3]), sticker[i + 1] + sticker[i + 3]),
                max(max(sticker[i] + sticker[i + 2] + sticker[i + 4], sticker[i] + sticker[i + 3]), sticker[i] + sticker[i + 3]),
                max(sticker[i + 2], sticker[i + 1] + sticker[i + 3]),
                max(max(sticker[i + 1] + sticker[i + 4], sticker[i + 1] + sticker[i + 3]), sticker[i + 2] + sticker[i + 4])
                });
        }

        int cur_index = 0;
        while (cur_index + 1 < nodelist.size()) {
            Node new_node = {
                max(nodelist[cur_index].max_1 + nodelist[cur_index + 1].max_1, nodelist[cur_index].max_2 + nodelist[cur_index + 1].max_3),
                max(nodelist[cur_index].max_1 + nodelist[cur_index + 1].max_2, nodelist[cur_index].max_2 + nodelist[cur_index + 1].max_4),
                max(nodelist[cur_index].max_3 + nodelist[cur_index + 1].max_1, nodelist[cur_index].max_4 + nodelist[cur_index + 1].max_3),
                max(nodelist[cur_index].max_3 + nodelist[cur_index + 1].max_2, nodelist[cur_index].max_4 + nodelist[cur_index + 1].max_4),
            };

            nodelist[++cur_index] = new_node;
        }

        answer = max(max(
            max(nodelist.back().max_1, nodelist.back().max_2),
            max(nodelist.back().max_3, nodelist.back().max_4)), answer);
    }

    return answer;
}

int main() {
    vector<int> sticker(1000);
    for (int i = 0; i < sticker.size(); i++) {
        sticker[i] = rand() % 100 + 1;
    }
    cout << solution(sticker);

	return 0;
}