#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();

    // First occurrence
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    int ans = -1;
    int last = -1;

    while(s <= e) {

        if(nums[mid] == target) {
            ans = mid;
            e = mid - 1;
        }
        else if(nums[mid] > target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }


    // Last occurrence
    s = 0;
    e = n - 1;
    mid = s + (e - s) / 2;

    while(s <= e) {

        if(nums[mid] == target) {
            last = mid;
            s = mid + 1;
        }
        else if(nums[mid] > target) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return {ans, last};
}


int main() {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter key to search: ";
    cin >> target;

    vector<int> result = searchRange(nums, target);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

    return 0;
}