class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>a(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            int s=prerequisites[i][1];
            int d=prerequisites[i][0];
            a[s].push_back(d);
        }
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                int neigh=a[i][j];
                indegree[neigh]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int res=0;
        while(!q.empty())
        {
            int  node=q.front();
            q.pop();
            res++;
            for(int j=0;j<a[node].size();j++)
            {
                int neigh=a[node][j];
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }

            }
        }
        if(res==n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};





















        
    