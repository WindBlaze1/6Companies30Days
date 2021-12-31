// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{
    string res;
    char c(src[0]);
    int k=1;
    for(int i=1; i<src.size(); i++){
        if(c == src[i])
            k++;
        else{
            res += c + to_string(k);
            k=1;
        }
        c = src[i];
    }
    res += c + to_string(k);
    return res;
}     
 
