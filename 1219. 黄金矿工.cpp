class Solution {
public:
  int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int m;
int n;
bool vb[15][15];
int dfs(int a,int b, vector<vector<int>>& grid)
{
	vb[a][b] = true;
	int mx = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = dx[i] + a;
		int y = dy[i] + b;
		if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && vb[x][y] == false)
		{
			mx = max(dfs(x, y, grid), mx);
		}
	}
	vb[a][b] = false;
	return mx+grid[a][b];
}
int getMaximumGold(vector<vector<int>>& grid) {
	m = grid.size();
	n = grid[0].size();
	int mx = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j])
			{
				mx = max(dfs(i, j, grid), mx);
			}
		}
	}
	return mx;
}
};
