class Solution {
    struct node{
        int i,j,cur;
        node(int a, int b, int c):
            i(a), j(b), cur(c) {}
        node(int a, int b):
            node(a,b,0) {}
        node():
            node(0,0,0) {}
    };
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int res(0);
        
        queue<node>q;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    node k(i,j);
                    q.push(k);
                }
            }
        }
        dfs(grid,q,res);
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                // cout<<grid[i][j]<<' ';
                if(grid[i][j] == 1)
                    return -1;
            }
            cout<<endl;
        }
        
        return res;
        
    }
    
    void dfs(vector<vector<int>>& grid, queue<node>&q, int &res){
        
        node temp;
        
        while(!q.empty()){
            
            temp = q.front();
            q.pop();
            
            int i = temp.i, j = temp.j, cur = temp.cur;
            
            res = max(res,cur);
            
            if(i+1>=0 && i+1<grid.size() && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                node k(i+1,j,cur+1);
                q.push(k);
            }
            
            if(i-1>=0 && i-1<grid.size() && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                node k(i-1,j,cur+1);
                q.push(k);
            }
            if(j+1>=0 && j+1<grid[0].size() && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                node k(i,j+1,cur+1);
                q.push(k);
            }
            if(j-1>=0 && j-1<grid[0].size() && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                node k(i,j-1,cur+1);
                q.push(k);
            }
            
        }
        
    }
    
};
