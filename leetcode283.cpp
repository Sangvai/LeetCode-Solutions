#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int k = 0;

    // Non-zero elements ko front mein rakho
    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Remaining positions mein zero daalo
    while (k < nums.size()) {
        nums[k] = 0;
        k++;
    }
}

void printArray(vector<int>& nums) {

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before: ";
    printArray(nums);

    moveZeroes(nums);

    cout << "After: ";
    printArray(nums);

    return 0;
}