class Solution {
public:
    vector<string> ret;
string path;
int len;
void dfs(string s,int k)
{
	if (k == len)
	{
		ret.emplace_back(path);
		return;
	}
	if ((s[k] >= 'A' && s[k] <= 'Z') ||( s[k] >= 'a' && s[k] <= 'z'))
	{
		path += s[k];
		dfs(s, k + 1);
		path.pop_back();
	}
	if (s[k] >= 'A' && s[k] <= 'Z')
	{
		path+= s[k] + 32;
		dfs(s, k + 1);
		path.pop_back();
	}
	else if(s[k] >= 'a' && s[k] <= 'z')
	{
		path += s[k] - 32;
		dfs(s, k + 1);
		path.pop_back();
	}
	else
	{
		path+= s[k];
		dfs(s, k + 1);
		path.pop_back();
	}
}
vector<string> letterCasePermutation(string s) {
	len = s.length();
	dfs(s, 0);
	return ret;
}
};
