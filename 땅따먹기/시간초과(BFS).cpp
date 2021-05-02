/*
struct queue_info {
    int index, depth, sum;
};

int solution(vector<vector<int>> land) {
    int answer = 0;

    vector<vector<int>> visit(land.size() + 1, vector<int>(4));

    queue<queue_info> queue;
    for (int i = 0; i < 4; i++) {
        queue.push({ i, 0, 0 });
    }

    while (!queue.empty()) {
        queue_info info = queue.front();
        queue.pop();

        if (info.depth >= land.size()) {
            answer = max(answer, info.sum);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (i != info.index) {
                int depth = info.depth + 1;
                int sum = info.sum + land[info.depth][info.index];
                if (visit[depth][i] < sum) {
                    visit[depth][i] = sum;
                    queue.push({ i, depth, sum });
                }
            }
        }
    }

    return answer;
}
*/