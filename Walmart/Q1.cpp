
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start, int end)   {
         vector<pair<int,double>> adj[n+1];
        for (int i=0;i<edges.size();i++)
        {
            int u= edges[i][0],v= edges[i][1];
            adj[u].push_back({v,sp[i]});
            adj[v].push_back({u,sp[i]});
        }

        vector<double> prob(n,INT32_MIN);
        priority_queue<pair<double,int>> maxh;
        maxh.push({1,start});
        prob[start]=1;
        while(!maxh.empty())
        {
            pair<double,int> p= maxh.top();   maxh.pop();
             double currp= p.first;
            int u=p.second;
           
            
            for (auto temp: adj[u] )
            {
                int v= temp.first;
                double pb= temp.second;

                if (currp* pb > prob[v])
                {
                    prob[v]=currp* pb;
                    maxh.push({prob[v],v});
                }
            }
        }
        return ((prob[end]!=INT32_MIN)? prob[end]: 0);
        
        
    }
};
