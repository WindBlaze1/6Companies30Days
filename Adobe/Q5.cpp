// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
    vector<vector<long long>> dp;
  public:
    long long numOfWays(long long n, int x) {
        int num = pow(n, 1.0 / x);
        dp.resize(n + 1, vector<long long>(num + 1, -1));
        return util(n, x, num);
    }
    
    long long util(int n, int x, int curr) {
        if(n == 0) return 1;
        else if(curr == 0) return 0;
        long long &ans = dp[n][curr];
        if(ans != -1) return ans;
        long long power = pow(curr, x);
        return ans = (n - power >= 0 ? util(n - power, x, curr - 1): 0) + util(n, x, curr - 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
