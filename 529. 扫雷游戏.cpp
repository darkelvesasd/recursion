class Solution {
public:
typedef pair<int, int>pii;
int dx[8] = { -1,1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	int m = board.size();
	int n = board[0].size();
	int t1 = click[0];
	int t2 = click[1];
	if (board[t1][t2] == 'M')
	{
		board[t1][t2] = 'X';
		return board;
	}
	else if (board[t1][t2] == 'E')
	{
		stack<pii>s;
		s.emplace(pii(t1, t2));
		while (!s.empty())
		{
			pii t = s.top();
			s.pop();
			int count = 0;
			for (int i = 0; i < 8; i++)
			{
				int x = t.first + dx[i];
				int y = t.second + dy[i];
				if (x >= 0 && x < m && y >= 0 && y < n)
				{
					if (board[x][y] == 'M')
					{
						count++;
					}
				}
			}
			if (board[t.first][t.second] == 'E')
			{
				if (count == 0)
				{
					board[t.first][t.second] = 'B';
					for (int i = 0; i < 8; i++)
					{
						int x = t.first + dx[i];
						int y = t.second + dy[i];
						if (x >= 0 && x < m && y >= 0 && y < n)
						{
							s.emplace(pii(x, y));
						}
					}
				}
				else
				{
					board[t.first][t.second] = count + '0';
				}
			}
		}
	}
		return board;
}
};
