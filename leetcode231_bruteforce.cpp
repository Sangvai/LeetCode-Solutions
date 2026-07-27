#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i <= 30; i++) {
            int ans = pow(2, i);
            if (n == ans) {
                return true;
            }
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