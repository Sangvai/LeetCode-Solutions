#include <iostream>
using namespace std;

int maxProfit(int arr[], int n) {

    int minPrice = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {

        if(arr[i] < minPrice) {
            minPrice = arr[i];
        }

        int profit = arr[i] - minPrice;

        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
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

    cout << "Maximum profit is: " << maxProfit(arr, n);

    return 0;
}