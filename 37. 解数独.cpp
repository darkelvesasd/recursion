class Solution {
public:
bool row[9][9];
bool col[9][9];
bool blk[3][3][9];
bool vb[9][9];
int m;
int n;
bool ret;
void dfs(int x,int y,vector<vector<char>>&board)
{
	if (x == 9)
	{
		ret = true;
		return;
	}
	/*for (int i = x; i < m; i++)
	{
		for (int j = y; j < n; j++)
		{*/
	int i = x;
	int j = y;
			if (vb[i][j] == false)
			{
				for (int k = 0; k < 9; k++)
				{
					if (row[i][k] == false && col[j][k] == false && blk[i / 3][j / 3][k] == false)
					{
						row[i][k] = col[j][k] = blk[i / 3][j / 3][k] = vb[i][j] = true;
						board[i][j] = k + '1';
						if (j < 8)
						{
							dfs(i, j+1,board);
							if (ret == 1)
							{
								return;
							}
						}
						else
						{
							dfs(i+1, 0, board);
							if (ret == 1)
							{
								return;
							}
						}
						board[i][j] = '.';
						row[i][k] = col[j][k] = blk[i / 3][j / 3][k] = vb[i][j] = false;
					}
				}
				if (board[i][j] == '.')
				{
					return;
				}
			}
			else
			{
				if (j < 8)
				{
					dfs(i, j + 1, board);
					if (ret == 1)
					{
						return;
					}
				}
				else
				{
					dfs(i + 1, 0, board);
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
				row[i][board[i][j]-'1'] = true;
				col[j][board[i][j]-'1'] = true;
				blk[i / 3][j / 3][board[i][j] - '1'] = true;
				vb[i][j] = true;
			}
		}
	}
	dfs(0, 0, board);
}
};
