class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, int j){
        isConnected[i][j] = 0;
        for(int k=0; k<isConnected.size(); k++){
            if(isConnected[j][k]){
                    dfs(isConnected, j, k);
                }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    ans++;
                    dfs(isConnected, i, j);
                }
            }
        }
        return ans;
    }
};
