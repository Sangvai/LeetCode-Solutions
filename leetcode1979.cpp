#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int nums[100];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mn = nums[0];
    int mx = nums[0];

    // Find minimum and maximum
    for(int i = 1; i < n; i++) {
        if(nums[i] < mn) {
            mn = nums[i];
        }

        if(nums[i] > mx) {
            mx = nums[i];
        }
    }

    // Find GCD
    int gcd = 1;

    for(int i = 1; i <= mn; i++) {
        if(mn % i == 0 && mx % i == 0) {
            gcd = i;
        }
    }

    cout << "GCD of smallest and largest element is: " << gcd << endl;

    return 0;
}