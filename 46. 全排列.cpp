class Solution {
public:
vector<vector<int>>ret;
int n;
void dfs(vector<int>&nums,int k, vector<bool>b,vector<int>p)
{
	if (k == nums.size())
	{
		ret.emplace_back(p);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (b[i] == false)
		{
			p.emplace_back(nums[i]);
			b[i] = true;
			dfs(nums,1+k,b,p);
			p.pop_back();
			b[i] = false;
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	n = nums.size();
	vector<bool>b(n);
	dfs(nums, 0, b, {});
	return ret;
}
};
