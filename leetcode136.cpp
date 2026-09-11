#include <iostream>
using namespace std;

int singleNumber(int arr[], int n) {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main() {

    int arr[100], n;
    cout<<"enter size of array: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int answer = singleNumber(arr, n);

    cout << "Single number is: " << answer << endl;

    return 0;
}