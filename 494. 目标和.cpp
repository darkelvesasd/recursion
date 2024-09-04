class Solution {
public:
  int gt;
int gn;
int ret;
int path;
void dfs(int d,vector<int>&nums)
{
	if (gn == d)
	{
		if (path == gt)
		{
			ret += 1;
		}
		return;
	}
	path += nums[d];
	dfs(d + 1, nums);
	path -= 2*nums[d];
	dfs(d + 1, nums);
	path += nums[d];
}
int findTargetSumWays(vector<int>& nums, int target) {
	gt = target;
	gn = nums.size();
	dfs(0, nums);
	return ret;
}
};
