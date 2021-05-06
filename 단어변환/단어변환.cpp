#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_smillar_diffrent(const string& s1, const string& s2) {
    int diffrent_cnt = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            ++diffrent_cnt;
        }
    }

    return (diffrent_cnt == 1);
}

int answer = INT_MAX;
void word_transform(vector<string>& words, vector<bool>& visit, const string& begin, const string& target, int depth) {
    if (begin == target) {
        answer = min(depth, answer);
        return;
   }
    
    if (depth >= words.size()) {
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visit[i] && is_smillar_diffrent(begin, words[i])) {
            visit[i] = true;
            word_transform(words, visit, words[i], target, depth + 1);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visit(words.size());
    word_transform(words, visit, begin, target, 0);

    return answer == INT_MAX ? 0 : answer;
}

int main()
{
    std::cout << solution("hit", "cog", { "hot","dot","dog","lot","log","cog" });
}