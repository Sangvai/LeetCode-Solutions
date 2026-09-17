#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {

    if (n <= 0) {
        return false;
    }

    while (n % 3 == 0) {
        n = n / 3;
    }

    return n == 1;
}

int main() {

    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfThree(n)) {
        cout << n << " is a power of 3." << endl;
    }
    else {
        cout << n << " is not a power of 3." << endl;
    }

    return 0;
}