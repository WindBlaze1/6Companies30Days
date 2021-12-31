// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_set<int>st;
        int c;
        for(int i=0; i<n; i++)
            if(st.find(arr[i])==st.end()){
                st.insert(arr[i]);
            }
            else{
                c = arr[i];
            }
        int *a = new int[2];
        a[0] = c;
        for(int i=1; i<=n; i++)
            if(st.find(i)==st.end())
                a[1] = i;
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
