#include<bits/stdc++.h>

#define     fi(x,y) for(ll i(x); i<y; i++)      //fi(0,n)
#define     fj(x,y) for(ll j(x); j<y; j++)
#define     fk(x,y) for(ll k(x); k<y; k++)
#define     fa(x) for(auto i:x)                     //range based
#define     ll long long
#define     ull unsigned ll
using namespace std;

void solve(){
    ll n;
    cin>>n;
    cout<<n*(n+1)*(2*n+1)/6<<'\n';
}

int main() {

    ull t(1);
    cin>>t;
    while(t--)
    {solve();}

    return 0;
}
