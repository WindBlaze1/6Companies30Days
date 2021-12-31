
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int recur(string str, int a[], int cur=0){
	        if (cur==str.size() || cur==str.size()-1)
	            return 1;
	        int k=0;
	        switch(str[cur]){
	            case '0': return 0;
	            case '1':{
	                if(a[cur+1]!=-1)
	                    k = a[cur+1];
	                else
                    {
                        a[cur+1] = recur(str,a,cur+1);
                        k = a[cur+1];
                    }
	                if(a[cur+2]!=-1)
	                    k += a[cur+2];
	                else{
	                    a[cur+2] = recur(str,a,cur+2);
	                    k += a[cur+2];
	                }
	               // return recur(str,cur+1) + recur(str,cur+2);
	                break;
	            }
	            case '2':{
	                if(str[cur+1]<'7'){
                        if(a[cur+1]!=-1)
	                        k = a[cur+1];
    	                else
	                    {
	                        a[cur+1] = recur(str,a,cur+1);
	                        k = a[cur+1];
	                    }
    	                if(a[cur+2]!=-1)
    	                    k += a[cur+2];
    	                else{
    	                    a[cur+2] = recur(str,a,cur+2);
    	                    k += a[cur+2];
    	                }
	                }
	                if(a[cur+1]!=-1)
                        k = a[cur+1];
	                else
                    {
                        a[cur+1] = recur(str,a,cur+1);
                        k = a[cur+1];
                    }
	                break;
	            }
	            default:{
	                if(a[cur+1]!=-1)
                        k = a[cur+1];
	                else
                    {
                        a[cur+1] = recur(str,a,cur+1);
                        k = a[cur+1];
                    }
	            }
	        }
	        return k;
	    }
	
		int CountWays(string s){
		    if(s[0]=='0' || *s.rbegin()=='0')
		        return 0;
	       char c=s[0];
	       for(int i=1; i<s.size()-1; i++){
	           if(s[i] == '0' && c>'2')
	               return 0;
	           c=s[i];
	       }
	       
	       int n(s.size()),a[n+1];
	       a[0]=a[1]=1;
	       int mod(1'000'000'007);
	       
	       for(int i=1; i<=n; i++){
	           a[i]=0;
	           
	           if(s[i-1]>'0')
	            a[i] = a[i-1];
	           
	           if(s[i-2] == '1' || (s[i-2]=='2' && s[i-1]<'7'))
	            a[i] = (a[i]+a[i-2])%mod;
	       }
	       
	       return a[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
