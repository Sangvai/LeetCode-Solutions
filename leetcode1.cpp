#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {

        for (int j = i + 1; j < nums.size(); j++) {

            if (nums[i] + nums[j] == target) {

                return {i, j};
            }
        }
    }

    return {};
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if (ans.size() == 2) {

        cout << "Indices are: ";
        cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    } else {

        cout << "No valid pair found." << endl;
    }

    return 0;
}