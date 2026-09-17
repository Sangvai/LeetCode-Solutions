#include<bits/stdc++.h>
using namespace std;
int peak(vector <int> arr){
    int n= arr.size();
    int low=0, high=n-1;
    while(low<high){
        int mid= low+(high- low)/2;
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return arr[low];
}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Peak of mountain is: "<<peak(arr)<<endl;
    return 0;
}