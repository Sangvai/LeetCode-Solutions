#include <bits/stdc++.h>
using namespace std;

int findNumbers(vector<int>& nums) {

    int count = 0;

    for (int i = 0; i < nums.size(); i++) {

        int num = nums[i];
        int digits = 0;

        while (num > 0) {
            num = num / 10;
            digits++;
        }

        if (digits % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {

    vector<int> nums = {12, 345, 2, 6, 7896};

    int answer = findNumbers(nums);

    cout << "Numbers with even number of digits: " << answer << endl;

    return 0;
}