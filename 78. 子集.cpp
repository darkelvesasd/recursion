class Solution {
public:
    vector<vector<int>>ret= { {} };
vector<int>path;
int n;
void dfs(vector<int>nums, int k)
{
	for (int i = k; i < n; i++)
	{
		path.emplace_back(nums[i]);
		ret.emplace_back(path);
		dfs(nums,i+1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	n = nums.size();
	dfs(nums,0);
	return ret;
}
};
