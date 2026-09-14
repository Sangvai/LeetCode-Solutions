#include <bits/stdc++.h>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

    if (rec1[2] <= rec2[0] ||   // rec1 left side mein hai
        rec2[2] <= rec1[0] ||   // rec2 left side mein hai
        rec1[3] <= rec2[1] ||   // rec1 neeche hai
        rec2[3] <= rec1[1]) {   // rec2 neeche hai

        return false;
    }

    return true;
}

int main() {

    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};

    if (isRectangleOverlap(rec1, rec2)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}