class Solution {
public:
    vector<vector<int>>ret;
int gt;
int gn;
vector<int>path;
int sp;
void dfs(vector<int>&candidates,int d)
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
		sp += candidates[i];
		path.emplace_back(candidates[i]);
		dfs(candidates, i);
		path.pop_back();
		sp -= candidates[i];
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	gn = candidates.size();
	gt = target;
	dfs(candidates, 0);
	return ret;
}
};
