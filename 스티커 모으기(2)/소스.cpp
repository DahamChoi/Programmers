/*

int solution(vector<int> sticker) {
    sticker.insert(sticker.begin(), 0);
    sticker.insert(sticker.begin(), 0);
    sticker.insert(sticker.end(), 0);

    int answer = 0;
    int last_number = sticker.back();

    for (int i = 0; i < 2; i++) {
        vector<int> index_max = vector<int>(sticker.size() + 1, -1);
        vector<pair<int, int>> stack;
        stack.push_back({ i,0 });

        if (i == 0) {
            if(sticker.size() > 3)
                sticker[sticker.size() - 1] = 0;
        }
        else {
            sticker[sticker.size() - 1] = last_number;
        }

        while (!stack.empty()) {
            int cur_index = stack.back().first;
            int cur_max = stack.back().second;
            stack.erase(stack.end() - 1);

            if (cur_index >= sticker.size() - 1) {
                answer = max(cur_max, answer);
                continue;
            }

            int sum = cur_max + sticker[cur_index];
            if (index_max[cur_index] < sum) {
                index_max[cur_index] = sum;
                index_max[cur_index + 1] = cur_max + sticker[cur_index + 1];
                stack.push_back({ cur_index + 3, sum });
                stack.push_back({ cur_index + 2, sum });
            }
        }
    }

    return answer;
}

*/