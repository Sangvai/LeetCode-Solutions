#include <iostream>
using namespace std;

bool uniqueOccurrences(int arr[], int n) {

    int freq[2001] = {0};

    // Count frequency of every number
    for(int i = 0; i < n; i++) {
        freq[arr[i] + 1000]++;
    }

    // Check whether frequencies are unique
    bool used[1001] = {false};

    for(int i = 0; i < 2001; i++) {

        if(freq[i] > 0) {

            if(used[freq[i]]) {
                return false;
            }

            used[freq[i]] = true;
        }
    }

    return true;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(uniqueOccurrences(arr, n)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}