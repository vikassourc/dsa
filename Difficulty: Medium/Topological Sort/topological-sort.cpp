class Solution {
public:

    void dfs(int node, vector<int>& vis, stack<int>& st,
             vector<vector<int>>& adj)
    {
        vis[node]=1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,st,adj);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);

        // Create adjacency list
        for(int i=0;i<edges.size();i++)
        {
            int src=edges[i][0];
            int dest=edges[i][1];

            adj[src].push_back(dest);
        }

        vector<int> vis(V,0);

        stack<int> st;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,st,adj);
            }
        }

        vector<int> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};