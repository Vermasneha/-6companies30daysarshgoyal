class Solution {
public:
    void dfs(vector<vector<int>>&grid,int r,int c,vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=delrow[i]+r;
            int nc=delcol[i]+c;
            if(nr>=0&& nr<m&& nc>=0 && nc<n &&!vis[nr][nc] && grid[nr][nc])
            dfs(grid,nr,nc,vis);
        }
    }
    int count(vector<vector<int>>&grid)
    {
          
         int m=grid.size();
        int n=grid[0].size();
        int islandCount=0;
         vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] &&!vis[i][j])
                {
                    islandCount++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return islandCount;
    }
    int minDays(vector<vector<int>>& grid) {
        //answer can be either 0,1,2
        //if(fully disconnected i.e more than one component) ans=0
        //else 1 or 2
        int m=grid.size();
        int n=grid[0].size();
     
        //check if multiple components
        int islandCount=count(grid);
        
        if(islandCount>1)
        return 0;
        //one by one remove every 1 and check if its island or not
        int onecount=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    onecount++;
                    grid[i][j]=0;
                    if(count(grid)>1)
                    return 1;
                    grid[i][j]=1;

                }
            }
        }
        if(onecount==0)
        return 0;
        if(onecount==1)
        return 1;
        return 2;

        
    }
};
