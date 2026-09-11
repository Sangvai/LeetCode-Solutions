#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;

    sort(nums.begin(), nums.end());

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) {
            ans.push_back(nums[i]);
        }
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = findDuplicates(nums);

    cout << "Duplicate elements are: ";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}