class Solution {
public:
    vector<vector<int>>ret;
vector<int>path;
bool b[8];
int n;
void dfs(vector<int>& nums, int k)
{
	int t = INT_MIN;
	if (path.size() == n)
	{
		ret.emplace_back(path);
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i]==false&&(t==INT_MIN||t!=nums[i]))
		{
			path.emplace_back(nums[i]);
			b[i] = true;
			dfs(nums, i);
			t = path.back();
			path.pop_back();
			b[i] = false;
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	n = nums.size();
	sort(nums.begin(), nums.end());
	dfs(nums, -1);
	return ret;
}
};
