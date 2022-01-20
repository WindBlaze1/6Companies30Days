// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum(0);
        sum = accumulate(arr,arr+n,0);
        if(sum%2) return 0;
        sum = sum/2;
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
        
        // initialize
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        
        // calculate
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        
        return dp[n][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
