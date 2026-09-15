#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {

        swap(s[left], s[right]);

        left++;
        right--;
    }
}

void printArray(vector<char>& s) {

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    cout << endl;
}

int main() {

    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Before: ";
    printArray(s);

    reverseString(s);

    cout << "After: ";
    printArray(s);

    return 0;
}