#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for (int i = 0; i <= 30; i++) {
            if (n == ans) {
                return true;
            }
            if (ans < INT_MAX / 2)
                ans = ans * 2;
        }
        return false;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isPowerOfTwo(n))
        cout << n << " is a Power of Two." << endl;
    else
        cout << n << " is NOT a Power of Two." << endl;

    return 0;
}