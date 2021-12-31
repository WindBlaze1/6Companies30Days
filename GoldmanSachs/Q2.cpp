// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool insideRect(int tl[], int br[], int x, int y){
        if (tl[0] <= x && br[0] >= x && tl[1] >= y && br[1] <= y)
            return true;
        return false;
    }
    
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        
        int hor(1),ver(1);
        if(l1[1] < r2[1] || l2[1] < r1[1])
            hor = 0;
        if(r1[0] < l2[0] || r2[0] < l1[0])
            ver = 0;
        return hor && ver;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
