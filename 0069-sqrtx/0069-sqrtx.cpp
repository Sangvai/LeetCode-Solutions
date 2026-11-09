class Solution {
public:

    long long binary(int n){
        int s=0;
        int e=n;
        int mid;
        long long  ans=-1;
        while(s<=e){
            mid= s+(e-s)/2;
            long long int sq = 1LL * mid * mid;
            if(sq==n){
                return mid;
            }
            if(sq<n){
                ans= mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return binary(x);
        
    }
};