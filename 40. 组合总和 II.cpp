class Solution {
public:
   int gn;
int gt;
vector<int>path;
int sp;
vector<vector<int>>ret;
void dfs(vector<int>& candidates,int d)
{
	if (sp >= gt)
	{
		if (sp == gt)
		{
			ret.emplace_back(path);
		}
		return;
	}
	for (int i = d; i < gn; i++)
	{
		if (i == d || candidates[i] != candidates[i-1])
		{
			sp += candidates[i];
			path.emplace_back(candidates[i]);
		//	b[i] = true;
			dfs(candidates, i + 1);
			sp -= candidates[i];
			path.pop_back();
			//b[i] = false;
		}
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	gn = candidates.size();
	gt = target;
	sort(candidates.begin(),candidates.end());
	dfs(candidates, 0);
	return ret;
}
};
