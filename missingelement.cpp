#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==0 || n==1) return 1;
    for(int i=2;i<=n;i++){
        n*=i;
    }
    return n;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    while(n!=0){
        int digit= n%10;
        sum=factorial(digit);
        n=n/10;
    }
    if(sum==n){
        cout<<"The number is a Strong Number."<<endl;       
    }
    else{
        cout<<"The number is NOT a Strong Number."<<endl;
    }   
}