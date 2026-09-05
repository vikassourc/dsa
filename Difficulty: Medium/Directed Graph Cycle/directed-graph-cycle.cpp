class Solution {
  public:
    bool cycle=false;
    void dfs(vector<vector<int>>&a,int node,vector<bool>&vis,vector<bool>&path)
    {
        vis[node]=true;
        path[node]=true;
        for(int j=0;j<a[node].size();j++)
        {
            int neigh=a[node][j];
            if(path[neigh]==true)
            {
                cycle=true;
            }
            if(vis[neigh]==false)
            {
                dfs(a,neigh,vis,path);
            }
        }
        path[node]=false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>a(V+1);
        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];
            a[src].push_back(dest);
        }
        vector<bool>vis(V+1,false);
        vector<bool>path(V+1,false);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
            {
                dfs(a,i,vis,path);
            }
        }
        return cycle;
    }
};
        
     