#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string ans = strs[0];

    for (int i = 1; i < strs.size(); i++) {

        int j = 0;

        while (j < ans.size() &&
               j < strs[i].size() &&
               ans[j] == strs[i][j]) {

            j++;
        }

        ans = ans.substr(0, j);

        if (ans == "") {
            return "";
        }
    }

    return ans;
}

int main() {

    vector<string> strs = {
        "flower",
        "flow",
        "flight"
    };

    string answer = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << answer << endl;

    return 0;
}