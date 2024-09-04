class Solution {
public:
  vector<vector<int>>ret;
vector<int>path;
int sp;
int gn;
int gk;
int k;
void dfs(int s)
{
	if (sp >= gn||k>=gk)
	{
		if (sp == gn && k == gk)
		{
			ret.emplace_back(path);
		}
		return;
	}
	for (int i = s; i <= 9; i++)
	{
		path.emplace_back(i);
		sp += i;
		k+=1;
		dfs(i + 1);
		k -= 1;
		path.pop_back();
		sp -= i;
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	gk = k;
	gn = n;
	dfs(1);
	return ret;
}
};
