class Solution {
public:
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
bool vb[6][6];
string w;
int m;
int n;
int ln;
bool dfs(int i,int j,int d, vector<vector<char>>& board)
{
	if (i == m)
	{
		return false;
	}
	if (w[d] == board[i][j])
	{
		d++;
		vb[i][j] = true;
		if (d == ln)
		{
			return true;
		}
		for (int k = 0;k < 4; k++)
		{
			int xt = dx[k] + i;
			int yt = dy[k] + j;
			if (xt >= 0 && xt < m && yt >= 0 && yt < n&&vb[xt][yt]==false)
			{
				if (dfs(xt, yt, d, board))
				{
					return true;
				}
			}
		}
		d--;
		vb[i][j] = false;
	}
	if(d==0)
	{
		if (j < n - 1)
		{
			if (dfs(i, j + 1, d, board))
			{
				return true;
			}
		}
		else
		{
			if (dfs(i + 1, 0, d, board))
			{
				return true;
			}
		}
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	w = word;
	m = board.size();
	n = board[0].size();
	ln = word.size();
	return dfs(0, 0, 0, board);
}
};
