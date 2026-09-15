#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k) {

    for (int i = 0; i < s.size(); i += 2 * k) {

        int left = i;
        int right = min(i + k - 1, (int)s.size() - 1);

        while (left < right) {
            swap(s[left], s[right]);

            left++;
            right--;
        }
    }

    return s;
}

int main() {

    string s = "abcdefg";
    int k = 2;

    string answer = reverseStr(s, k);

    cout << "Original String: " << s << endl;
    cout << "After Reversal: " << answer << endl;

    return 0;
}