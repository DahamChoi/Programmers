#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

static int const BENEFIT = 100;

struct emp {
    string referral;
    int result{ 0 }, grade{ 0 };
    vector<int> amount;
};

void exact_referral(unordered_map<string, emp>& organization, const string& name, int benefit) {
    if (name != "-") {
        organization[name].result += ceil(benefit * 0.9);
        exact_referral(organization, organization[name].referral, (benefit / 10));
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    unordered_map<string, emp> organization;
    organization["-"] = { "", 0, 0 };

    int exact_num = 0;
    for (int i = 0; i < enroll.size(); i++) {
        exact_num = max(exact_num, organization[referral[i]].grade + 1);
        organization[enroll[i]] = { referral[i], 0, organization[referral[i]].grade + 1 };
    }

    for (int i = 0; i < seller.size(); i++) {
        organization[seller[i]].amount.push_back(amount[i] * BENEFIT);
    }

    while (exact_num > 0) {
        for (auto& it : organization) {
            if (it.second.grade == exact_num) {
                for (int i = 0; i < it.second.amount.size(); i++) {
                    exact_referral(organization, organization[it.first].referral, it.second.amount[i] * 0.1);
                    it.second.amount[i] = ceil(it.second.amount[i] * 0.9);
                }
            }
        }

        --exact_num;
    }

    for (int i = 0; i < enroll.size(); i++) {
        int n = 0;
        for (int j = 0; j < organization[enroll[i]].amount.size(); j++) {
            n += organization[enroll[i]].amount[j];
        }
        answer.push_back(organization[enroll[i]].result + n);
    }

    return answer;
}

int main()
{
    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> seller = { "young", "john", "tod", "emily", "mary" };
    vector<int> amount = { 12, 4, 2, 5, 10 };

    vector<int> answer = solution(enroll, referral, seller, amount);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}