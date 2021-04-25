#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<long long> factorial_list = { 
        0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,
        6227020800,87178291200,1307674368000,20922789888000,355687428096000,
        6402373705728000,121645100408832000,2432902008176640000 };

    vector<int> permutation(n), numberic_list(n);
    for (int i = 0; i < numberic_list.size(); i++) {
        numberic_list[i] = i + 1;
    }

    --k;
    for (int i = 0; i < permutation.size() - 1; i++) {
        int number_index = k / factorial_list[n - 1];
        permutation[i] = numberic_list[number_index];
        numberic_list.erase(numberic_list.begin() + number_index);
        k = k % factorial_list[n-- - 1];
    }
    permutation[permutation.size() - 1] = numberic_list.front();

    return permutation;
}

int main()
{
    vector<int> answer = solution(3, 1);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}