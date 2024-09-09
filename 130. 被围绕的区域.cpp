class Solution {
public:
typedef pair<int, int>pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
void solve(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>>vb(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
	{
		stack<pii>s;
		if (board[i][n - 1] == 'O' && vb[i][n - 1] == false)
		{
			s.emplace(pii(i, n - 1));
			vb[i][n - 1] = true;
		}
		if (board[i][0] == 'O' && vb[i][0] == false)
		{
			s.emplace(pii(i, 0));
			vb[i][0] = true;
		}
		while (!s.empty())
		{
			pii t = s.top();
			s.pop();
			for (int k = 0; k < 4; k++)
			{
				int x = t.first + dx[k];
				int y = t.second + dy[k];
				if (x >= 0 && x < m && y >= 0 && y < n && vb[x][y] == false && board[x][y] == 'O')
				{
					s.emplace(pii(x, y));
					vb[x][y] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		stack<pii>s;
		if (board[0][i] == 'O' && vb[0][i] == false)
		{
			s.emplace(pii(0, i));
			vb[0][i] = true;
		}
		if (board[m - 1][i] == 'O' && vb[m - 1][i] == false)
		{
			s.emplace(pii(m - 1, i));
			vb[m - 1][i] = true;
		}
		while (!s.empty())
		{
			pii t = s.top();
			s.pop();
			for (int k = 0; k < 4; k++)
			{
				int x = t.first + dx[k];
				int y = t.second + dy[k];
				if (x >= 0 && x < m && y >= 0 && y < n && vb[x][y] == false && board[x][y] == 'O')
				{
					s.emplace(pii(x, y));
					vb[x][y] = true;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'O' && vb[i][j] == true)
			{
			}
			else
			{
				board[i][j] = 'X';
			}
		}
	}
}
};
