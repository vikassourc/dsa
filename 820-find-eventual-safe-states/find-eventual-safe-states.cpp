class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>rev(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(auto it: graph[i])
            {
                rev[it].push_back(i);
            }
        }
        vector<int>indegree(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<rev[i].size();j++)
            {
                int neigh=rev[i][j];
                indegree[neigh]++;
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty())
        {
            int node=q.front();
            res.push_back(node);
            q.pop();
            for(int j=0;j<rev[node].size();j++)
            {
                int neigh=rev[node][j];
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
        
  