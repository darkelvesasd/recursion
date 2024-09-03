class Solution {
public:
    int ret;
vector<int> path;
int n;
void dfs(vector<int>& nums, int k)
{
	int sum = 0;
	for (auto p : path)
	{
		sum ^= p;
	}
	ret += sum;
	for (int i = k; i < n; i++)
	{
		path.emplace_back(nums[i]);
		dfs(nums, i + 1);
		path.pop_back();
	}
}
int subsetXORSum(vector<int>& nums) {
	n = nums.size();
	dfs(nums, 0);
	return ret;
}
};
