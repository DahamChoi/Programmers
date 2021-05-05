#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct member {
    vector<int> childern, team_numbers;
    int parent{ 0 }, sales{ 0 }, index{ 0 };
};

int current_team_number = 0;
void set_team_numbers(vector<member>& organization, int team_number, int index) {
    if (!organization[index].childern.empty()) {
        organization[index].team_numbers.push_back(team_number);

        ++current_team_number;
        for (int i = 0; i < organization[index].childern.size(); i++) {
            organization[organization[index].childern[i]].team_numbers.push_back(team_number);
            set_team_numbers(organization, current_team_number, organization[index].childern[i]);
        }
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;

    vector<member> organization(sales.size());
    for (int i = 0; i < links.size(); i++) {
        organization[links[i][0] - 1].childern.push_back(links[i][1] - 1);
        organization[links[i][1] - 1].parent = links[i][0] - 1;
    }

    set_team_numbers(organization, current_team_number, 0);

    for (int i = 0; i < sales.size(); i++) {
        organization[i].index = i;
        organization[i].sales = sales[i];
    }

    vector<vector<member*>> team_map(current_team_number);
    for (int i = 0; i < organization.size(); i++) {
        for (int j = 0; j < organization[i].team_numbers.size(); j++) {
            team_map[organization[i].team_numbers[j]].push_back(&organization[i]);
        }
    }

    for (int i = 0; i < team_map.size(); i++) {
        sort(team_map[i].begin(), team_map[i].end(), [](const member* m1, const member* m2) {
            return m1->sales < m2->sales;
            });

        int n = team_map[i].front()->sales;
        if (team_map[i].front()->team_numbers.size() <= 1) {
            for (int j = 0; j < team_map[i].size(); j++) {
                if (team_map[i][j]->team_numbers.size() > 1) {
                    team_map[i][j]->team_numbers.erase(team_map[i][j]->team_numbers.begin());
                }
                team_map[i][j]->sales -= n;
            }
        }
        
        answer += n;
    }

    return answer;
}

int main()
{
    vector<int> sales = { 14, 17, 15, 18, 19, 14, 13, 16, 28, 17 };
    vector<vector<int>> links = { {10,8},{1,9},{9,7},{5,4},{1,5},{5,10},{10,6},{1,3},{10,2} };


    std::cout << solution(sales, links);
}