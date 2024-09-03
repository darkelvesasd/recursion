class Solution {
public:
   int l;
int r;
vector<string>ret;
string path;
void dfs(int &n,int k)
{
	if (2*n == k)
	{
		ret.emplace_back(path);
		return;
	}
	if (l < n)
	{
		l++;
		path += "(";
		dfs(n, 1+k);
		l--;
		path.pop_back();
	}
	if (r < l)
	{
		r++;
		path += ")";
		dfs(n, 1 + k);
		r--;
		path.pop_back();
	}
}
vector<string> generateParenthesis(int n) {
	dfs(n, 0);
	return ret;
}
};
