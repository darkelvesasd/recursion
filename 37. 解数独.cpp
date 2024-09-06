class Solution {
public:
   bool row[9][9];
bool col[9][9];
bool blk[3][3][9];
bool vb[9][9];
int m;
int n;
bool ret;
void dfs(int x, int y, vector<vector<char>>& board)
{
	if (x == 9)
	{
		ret = true;
		return;
	}
	if (vb[x][y] == false)
	{
		for (int k = 0; k < 9; k++)
		{
			if (row[x][k] == false && col[y][k] == false && blk[x / 3][y / 3][k] == false)
			{
				row[x][k] = col[y][k] = blk[x / 3][y / 3][k] = vb[x][y] = true;
				board[x][y] = k + '1';
				if (y < 8)
				{
					dfs(x, y + 1, board);
					if (ret == 1)
					{
						return;
					}
				}
				else
				{
					dfs(x + 1, 0, board);
					if (ret == 1)
					{
						return;
					}
				}
				board[x][y] = '.';
				row[x][k] = col[y][k] = blk[x / 3][y / 3][k] = vb[x][y] = false;
			}
		}
		if (board[x][y] == '.')
		{
			return;
		}
	}
	else
	{
		if (y < 8)
		{
			dfs(x, y + 1, board);
			if (ret == 1)
			{
				return;
			}
		}
		else
		{
			dfs(x + 1, 0, board);
			if (ret == 1)
			{
				return;
			}
		}
	}
}
void solveSudoku(vector<vector<char>>& board) {
	m = board.size();
	n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != '.')
			{
				row[i][board[i][j] - '1'] = true;
				col[j][board[i][j] - '1'] = true;
				blk[i / 3][j / 3][board[i][j] - '1'] = true;
				vb[i][j] = true;
			}
		}
	}
	dfs(0, 0, board);
}
};
