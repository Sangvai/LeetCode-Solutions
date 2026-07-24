#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int m = n;
        int mask = 0;

        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        return (~n) & mask;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Bitwise Complement: " << obj.bitwiseComplement(n) << endl;

    return 0;
}