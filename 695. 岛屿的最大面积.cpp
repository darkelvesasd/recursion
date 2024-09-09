class Solution {
public:
    typedef pair<int, int>pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int maxAreaOfIsland(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	int ret = 0;
	vector<vector<bool>>vb(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1&&vb[i][j]==false)
			{
				int count = 0;
				stack<pii>s;
				s.emplace(pii(i, j));
				vb[i][j] = true;
				while (!s.empty())
				{
					pii t = s.top();
					s.pop();
					count++;
					for (int k = 0; k < 4; k++)
					{
						int x = t.first + dx[k];
						int y = t.second + dy[k];
						if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1&&vb[x][y]==false)
						{
							s.emplace(pii(x, y));
							vb[x][y] = true;
						}
					}
				}
				ret = max(ret, count);
			}
		}
	}
	return ret;
}
};
