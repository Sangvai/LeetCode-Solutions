/*
LeetCode 7 - Reverse Integer

Approach:
- Extract the last digit of the number using modulo (% 10).
- Build the reversed number by multiplying the current answer by 10 and adding the extracted digit.
- Before updating the answer, check for integer overflow.
- If overflow is possible, return 0.
- Repeat until all digits are processed.

Time Complexity: O(log10(n))
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;

            // Overflow check
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;

            ans = ans * 10 + digit;
            x = x / 10;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int x;
    cout << "Enter number: ";
    cin >> x;

    cout << "Reversed number: " << obj.reverse(x) << endl;

    return 0;
}