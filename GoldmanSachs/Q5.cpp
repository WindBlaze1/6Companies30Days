// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    
	    if(n == 1)
	        return 1;
	    
	    set<ull>st;
	    st.insert(1);
	    n--;
	    
	    while(n) {
	        ull k = *st.begin();
	        st.erase(st.begin());
	        st.insert(k*2);
	        st.insert(k*3);
	        st.insert(k*5);
	        n--;
	    }
	    
	   // for(auto i:st)
	   //     cout<<i<<' ';
	    
	    return *st.begin();
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
