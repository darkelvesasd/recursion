class Solution {
public:
    bool col[9];
bool dgn[17];//y-x+9  
bool dgn1[17];//x+y
int gn;
vector<vector<string>>ret;
vector<string>path;
string st;
void dfs(int y)
{
	if (y == gn)
	{
		ret.emplace_back(path);
		return;
	}
	string st;
	for (int x=0;x<gn;x++)
	{
		if (col[x] == false && dgn[y-x+8]==false&&dgn1[y+x]==false)
		{
			st += "Q";
			col[x] = true;
			dgn[y - x + 8] = true;
			dgn1[y + x] = true;
			int xt = x;
			while (xt < gn-1)
			{
				xt++;
				st += ".";
			}
			path.emplace_back(st);
			dfs(y+1);
			st[x] = '.';
			while (xt > x)
			{
				xt--;
				st.pop_back();
			}
			path.pop_back();
			col[x] = false;
			dgn[y - x + 8] = false;
			dgn1[y + x] = false;
		}
		else
		{
			st += ".";
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	gn = n;
	dfs(0);
	return ret;
}
};
