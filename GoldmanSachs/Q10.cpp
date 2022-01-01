#include<bits/stdc++.h>

#define     fi(x,y) for(ll i(x); i<y; i++)      //fi(0,n)
#define     fj(x,y) for(ll j(x); j<y; j++)
#define     fk(x,y) for(ll k(x); k<y; k++)
#define     fa(x) for(auto i:x)                     //range based
#define     ll long long
#define     ull unsigned ll
using namespace std;

void solve(){
    vector<ll> v(10,-1);
    make_heap(v.begin(),v.end());
    ll n;
    while(cin>>n){
        if(*v.begin() < n){
            pop_heap(v.begin(),v.end());
            v.pop_back();
            v.push_back(n);
            push_heap(v.begin(),v.end());
            sort_heap(v.begin(),v.end());
        }
        for(auto &i:v)
            cout<<i<<' ';
        cout<<endl;
    }
}

int main() {

    ull t(1);
    // cin>>t;
    while(t--)
    {solve();}

    return 0;
}
