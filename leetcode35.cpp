#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target, bool &found) {
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) {
            found = true;
            return mid;
        }
        else if (nums[mid] < target) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    found = false;
    return s;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    bool found;
    int index = searchInsert(nums, target, found);

    if (found) {
        cout << "Target found at index " << index << endl;
    }
    else {
        cout << "Target not found." << endl;
        cout << "Target should be inserted at index " << index << endl;
    }

    return 0;
}