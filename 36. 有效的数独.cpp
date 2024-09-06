class Solution {
public:
bool row[9][10];
bool col[9][10];
bool blk[3][3][10];
int m;
int n;
bool isValidSudoku(vector<vector<char>>& board) {
	m = board.size();
	n = board[0].size();
	for (int i = 0; i < m; i++)
	{
		for(int j=0;j<n;j++)
		{
			if (board[i][j] >= '1' && board[i][j] <= '9')
			{
				if (row[j][board[i][j] - '0'] == true || col[i][board[i][j] - '0'] == true || blk[i / 3][j / 3][board[i][j] - '0'] == true)
				{
					return false;
				}
				row[j][board[i][j] - '0'] = true;
				col[i][board[i][j] - '0'] = true;
				blk[i / 3][j / 3][board[i][j]-'0'] = true;
			}
		}
	}
	return true;
}
};
