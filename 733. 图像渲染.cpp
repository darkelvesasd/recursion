class Solution {
public:
    typedef pair<int, int>pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int m = image.size();
	int n = image[0].size();
	stack<pii>s;
	int val = image[sr][sc];
	if (val == color)
	{
		return image;
	}
	s.emplace(pii(sr, sc));
	while (!s.empty())
	{
		pii t = s.top();
		s.pop();
		image[t.first][t.second] = color;
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == val)
			{
				s.emplace(pii(x, y));
			}
		}
	}
	return image;
}
};
