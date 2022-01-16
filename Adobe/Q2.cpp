// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        int res(0);
        if(n<=2)
            return n;
        unordered_set<int>st;
        for(int i=0; i<n; i++)
            st.insert(A[i]);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int cur(3),d;
                d = A[j] - A[i];
                while(st.find(A[i] + (cur-1)*d) != st.end())
                    cur++;
                res = max(res,cur-1);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
