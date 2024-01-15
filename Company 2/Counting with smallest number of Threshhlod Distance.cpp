class Solution {
public:
    int oo = 1000001;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n , vector<int>(n , oo));
        int ver = 0;
        int mnCnt = oo;
        for (int i = 0 ; i<n ; i++)
          mat[i][i] = 0;
        for (int i = 0; i<edges.size() ; i++) {
          mat[edges[i][0]][edges[i][1]] = edges[i][2];
          mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int k = 0 ; k<n ; k++)
          for (int i = 0; i<n ; i++)
            for (int j = 0 ; j<n ; j++)
              if (mat[i][k] + mat[k][j] <= distanceThreshold)
                mat[i][j] = min(mat[i][j] , mat[i][k] + mat[k][j]);
        for (int i = 0 ; i<n ; i++) {
          int cnt =0;
          for (int j = 0; j<n ; j++)
            if (mat[i][j] <= distanceThreshold)
              cnt++;
          if (cnt <= mnCnt) {
            mnCnt = cnt;
            ver = i;
          }
        }
        return ver;
    }
};
