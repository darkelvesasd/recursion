class Solution {
public:
 typedef pair<int, int>pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m;
int n;
void dfs(vector<vector<int>>& heights, vector<vector<bool>>&vb,pii loc)
{
	stack<pii>s;
	s.emplace(loc);
	vb[loc.first][loc.second] = true;
	while (!s.empty())
	{
		pii t = s.top();
		s.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 0 && x < m && y >= 0 && y < n && vb[x][y] == false && heights[x][y] >= heights[t.first][t.second])
			{
				s.emplace(pii(x, y));
				vb[x][y] = true;
			}
		}
	}
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	m = heights.size();
	n = heights[0].size();
	vector<vector<int>>ret;
	vector<vector<bool>>vb(m, vector<bool>(n));
	vector<vector<bool>>vb1(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
	{
		dfs(heights, vb,pii( i, 0));
		dfs(heights, vb1, pii(i, n - 1));
	}
	for (int i = 0; i < n; i++)
	{
		dfs(heights, vb,pii(0,i));
		dfs(heights, vb1,pii( m-1, i));
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vb[i][j] == true && vb1[i][j] == true)
			{
				ret.push_back({ i,j });
			}
		}
	}
	return ret;
}
};
