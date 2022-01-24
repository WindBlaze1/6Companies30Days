class Solution {
public:
int maxDistance(vector<vector>& grid) {
int nr=grid.size();
int nc=grid[0].size();

    vector<vector<bool>> visited(nr);
    
    for(int i=0;i<nr;i++)
        visited[i].resize(nc,false);
    
    queue<pair<int,int>> q;
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            if(grid[i][j]==1){
                q.push({i,j});
            }
        }
    }
    helpBfs(grid,visited,q);
    int ans=-1;
    
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            if(grid[i][j]>1)
            ans=max(ans,grid[i][j]);
        }
    }
    return ans;
}

void helpBfs(vector<vector<int>>& grid,vector<vector<bool>> &visited, queue<pair<int,int>> &q){
    int nr=grid.size();
    int nc=grid[0].size();
    int level=0;
    
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    
    while(!q.empty()){
        int size=q.size();
       
  for(int i=0;i<size;i++){   
      pair<int,int> temp=q.front();
       q.pop();
        for(int i=0;i<4;i++){
            int x=temp.first+dx[i];
            int y=temp.second+dy[i];
            
            if(isValid(grid,visited,x,y)){
                q.push({x,y});
                visited[x][y]=true;
                
                if(level==0){
                    grid[x][y]=1;
                }
                else{
                    grid[x][y]=1+grid[temp.first][temp.second];
                }
            }
        }
      }
        level++;
    }
}

bool isValid(vector<vector<int>>& grid,vector<vector<bool>> &visited,int x,int y){
    int nr=grid.size();
    int nc=grid[0].size();
    
    if((x>=0 && x<nr) && (y>=0 && y<nc) && (!visited[x][y]) && grid[x][y]==0)
        return true;
    
    return false;
}

};
