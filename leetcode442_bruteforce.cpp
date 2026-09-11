#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {

    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {

        for(int j = i + 1; j < nums.size(); j++) {

            if(nums[i] == nums[j]) {
                ans.push_back(nums[i]);
                break;
            }
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