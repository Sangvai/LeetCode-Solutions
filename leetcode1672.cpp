#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {

    int maxWealth = 0;

    for (int i = 0; i < accounts.size(); i++) {

        int sum = 0;

        for (int j = 0; j < accounts[i].size(); j++) {
            sum = sum + accounts[i][j];
        }

        maxWealth = max(maxWealth, sum);
    }

    return maxWealth;
}

int main() {

    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1}
    };

    int answer = maximumWealth(accounts);

    cout << "Richest customer wealth: " << answer << endl;

    return 0;
}