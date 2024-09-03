class Solution {
public:
   int ret;
int path;
int n;
void dfs(vector<int>& nums, int k)
{
	ret += path;
	for (int i = k; i < n; i++)
	{
		path ^= nums[i];
		dfs(nums, i + 1);
		path ^= nums[i];
	}
}
int subsetXORSum(vector<int>& nums) {
	n = nums.size();
	dfs(nums, 0);
	return ret;
}
};
