// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        string res("1");
        for(int i=0; i<s.size(); i++)
            res += '2'+i;
        int j(1);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='D'){
                j=i;
                while(j<s.size() && s[j]=='D') j++;
                reverse(res.begin()+i,res.begin()+j+1);
                i = j;
            }
            
        }
        
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
