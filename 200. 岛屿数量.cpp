class Solution {
public:
    typedef pair<int, int>pii;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int numIslands(vector<vector<char>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>>vb(m, vector<bool>(n));
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == '1' && vb[i][j] == false)
			{
				count++;
				stack<pii>s;
				s.emplace(pii(i, j));
				vb[i][j] = true;
				while (!s.empty())
				{
					pii t = s.top();
					s.pop();
					for (int k = 0; k < 4; k++)
					{
						int x = dx[k] + t.first;
						int y = dy[k] + t.second;
						if (x >= 0 && x < m && y >= 0 && y < n&&grid[x][y]=='1' && vb[x][y] == false)
						{
							s.emplace(pii(x, y));
							vb[x][y] = true;
						}
					}
				}
			}
		}
	}
	return count;
}
};
