// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string res;
        char c(tolower(s[0]));
        res = c;
        for(int i=1; i<s.size(); i++){
            if(isupper(s[i])){
                // c = tolower(s[i]);
                res = res + " " + (char)tolower(s[i]);
            }
            else
                res += s[i];
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
