class Solution {
public:
    vector<vector<int>>ret;
vector<int>path;
int tn;
int tk;
void dfs(int d)
{
	if (path.size() == tk)
	{
		ret.emplace_back(path);
	}
	for (int i=d;i<=tn;i++)
	{
		path.emplace_back(i);
		dfs(i+1);
		path.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	tn = n;
	tk = k;
	dfs(1);
	return ret;
}
};
