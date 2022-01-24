class Solution {
public:
    vector<int> fa;
    
    void createGraph(vector<vector<int>> &graph,vector<vector<int>>&prereq){
        for(int i=0; i<prereq.size(); i++){
            graph[prereq[i][0]].push_back(prereq[i][1]);
        }
    }
    
    bool checkCycle(vector<vector<int>> &graph, int curr, vector<int> &visited){
        if(visited[curr] == 2){
            return true;
        }
        
        visited[curr] = 2;
        
        for(int i: graph[curr]){
            if(visited[i] != 1){
                bool ans;
                ans = checkCycle(graph, i, visited);
                if(ans == true){
                    return true;
                }
            }
        }
        
        visited[curr] = 1;
        return false;
    }
    
    void dfs(vector<vector<int>> &graph, int curr, vector<int> &visi){
        visi[curr] = 1;
        
        for(int i: graph[curr]){
            if(visi[i] == 0){
                dfs(graph, i, visi);
            }
        }
        fa.push_back(curr);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>&prerequisites){
        vector<vector<int>> graph(numCourses, vector<int>());
        createGraph(graph, prerequisites);
            
        vector<int> visited(numCourses, 0);
        
        // IF Cycle Exists Then return empty vector 
        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                bool finalans;
                finalans = checkCycle(graph, i, visited);
                if(finalans == true){
                    return fa;
                }
            }
        }
        
        // IF Cycle doesnt exist then do this
        vector<int> visited2(numCourses, 0);
        
        for(int i=0; i<numCourses; i++){
            if(visited2[i] == 0){
                dfs(graph, i, visited2);
            }
        }
        return fa;
    }
};
