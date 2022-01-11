
class Solution
{
    public:
    
    void recur(map<int,vector<char>>&mp, int a[], int n, vector<string> &strs,
               string s="", int cur=0){
        // if(n==cur)
        //     return;
        if(n==cur){
            strs.push_back(s);
            return;
        }
        for(int i=0; i<mp[a[cur]].size(); i++){
            recur(mp,a,n,strs,s+mp[a[cur]][i],cur+1);
        }
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        map<int,vector<char>>mp;
        mp = {
            {2,{'a','b','c'}},
            {3,{'d','e','f'}},
            {4,{'g','h','i'}},
            {5,{'j','k','l'}},
            {6,{'m','n','o'}},
            {7,{'p','q','r','s'}},
            {8,{'t','u','v'}},
            {9,{'w','x','y','z'}}
        };
        vector<string>strs;
        recur(mp,a,N,strs);
        
        return strs;
    }
};
