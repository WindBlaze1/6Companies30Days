#include <bits/stdc++.h>

int idx_left(int l, int r, int *a, int k)
{

    int mid = l + (r - l) / 2;

    while (l < r)
    {
        if (a[mid] < k)
            l = mid + 1;
        else if (a[mid] > k)
            r = mid - 1;
        else
            return mid;
        mid = l + (r - l) / 2;

    }
    return a[mid]==k?mid:-1;
}

int idx_right(int l, int r, int *a, int k)
{

    int mid = l + (r - l) / 2;


    while (l < r)
    {
        if (a[mid] > k)
            l = mid + 1;
        else if (a[mid] < k)
            r = mid - 1;
        else
            return mid;
        mid = l + (r - l) / 2;
    }
    return a[mid]==k?mid:-1;

}

using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,vector<pair<int,int>>> mp;
    for(int i=0; i<n; i++){
        vector<int> a;
        stringstream ss;
        int t;
        string c;
        cin>>c;
        ss<<c;
        // cout<<c<<"p\n";
        while(getline(ss,c,'.')){
            a.push_back(stoi(c));
        }
        // for(auto i:a) cout<<i<<' ';
        switch(a.size()){
            case 1:{
                mp[a[0]].push_back({0,0});
                break;
            }
            case 2:{
                mp[a[0]].push_back({a[1],0});
                break;
            }
            case 3:{
                mp[a[0]].push_back({a[1],a[2]});
            }
        }
    }
    sort(mp.rbegin()->second.rbegin(),mp.rbegin()->second.rend());
    
    // for(auto &i:mp){
    //     cout<<i.first<<":";
    //     for(auto &j:i.second){
    //         cout<<j.first<<','<<j.second;
    //     }
    //     cout<<endl;
    // }

    cout<<mp.rbegin()->first<<'.'<<mp.rbegin()->second[0].first<<'.'<<mp.rbegin()->second[0].second<<'\n';
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
