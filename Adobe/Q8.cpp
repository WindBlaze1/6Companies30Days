// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    void generate(vector<string> &v, string cur, int open, int close){
        if(open == close && open == 0){
            v.push_back(cur);
            return;
        }
        if(open)
            generate(v,cur+'(',open-1,close);
        if(close>open)
            generate(v,cur+')',open,close-1);
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>v,r;
        generate(v,"",n,n);
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
