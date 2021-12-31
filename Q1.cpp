// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string,int> mp;
        vector<vector<string>> ret;
        int n(0);
        for(auto i:string_list){
            // cout<<i<<'\n';
            string k = i;
            sort(k.begin(),k.end());
            if(mp.find(k) != mp.end()){
                // cout<<mp.find(k)->first<<'\n';
                ret[mp.find(k)->second].push_back(i);
            }
            else{
                ret.push_back({i});
                mp[k] = n;
                n++;
            }
        }
        
        return ret;
        
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
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
