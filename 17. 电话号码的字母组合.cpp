class Solution {
public:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ret;
string path;
int n;
void dfs(string digits,int k)
{
	if (k == n)
	{
		ret.emplace_back(path);
		return;
	}
	string t = s[digits[k]-'0'];
		for (int j = 0; j < t.size(); j++)
		{
			path += t[j];
			dfs(digits, k+1);
			path.pop_back();
		}
}
vector<string> letterCombinations(string digits) {
	n = digits.length();
	if (digits == "")
	{
		return {};
	}
	dfs(digits, 0);
	return ret;
}
};
