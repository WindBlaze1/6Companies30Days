// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    string nextPalin(string N) { 
        //complete the function here
        int n(N.size());
        if(n<=3)
            return "-1";
        string k(N.substr(0,n/2));
        if(next_permutation(k.begin(),k.end())){
            string res = k;
            if(n&1)
                res += N[n/2];
            reverse(k.begin(),k.end());
            res += k;
            return res;
        }
        return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
