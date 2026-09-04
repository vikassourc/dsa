class Solution {
public:

    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool valid(int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return false;
        }

        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n,vector<int>(m,-1));

        int i,j;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            for(int k=0;k<4;k++)
            {
                int row=r+x[k];
                int col=c+y[k];

                if(valid(row,col,n,m) && dist[row][col]==-1)
                {
                    dist[row][col]=dist[r][c]+1;
                    q.push({row,col});
                }
            }
        }

        return dist;
    }
};