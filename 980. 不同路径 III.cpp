class Solution {
public:
  int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
typedef pair<int, int>PII;
int c=0;
int m, n;
PII s, e;
int ret;
bool vb[20][20];
void dfs(PII a, vector<vector<int>>& grid,int count)
{
	if (a.first == e.first && a.second == e.second )
	{
		if (count - 1 == c)
		{
			ret++;
			return;
		}
		else
			return;
	}
	vb[a.first][a.second] = true;
	count++;
	for (int i = 0; i < 4; i++)
	{
		int x = a.first + dx[i];
		int y = a.second + dy[i];
		if (x >= 0 && x < m && y >= 0 && y < n && vb[x][y] == false&&(0==grid[x][y]||grid[x][y]==2))
		{
			dfs(PII(x, y), grid,count);
		}
	}
	vb[a.first][a.second] = false;
}
int uniquePathsIII(vector<vector<int>>& grid) {
	 m = grid.size();
	 n = grid[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!grid[i][j])
			{
				c++;
			}
			else if (grid[i][j] == 1)
			{
				s.first = i;
				s.second = j;
			}
			else if(grid[i][j]==2)
			{
				e.first = i;
				e.second = j;
			}
		}
	}
	dfs(s, grid,0);
	return ret;
}
};
