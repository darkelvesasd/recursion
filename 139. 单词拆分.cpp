class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.length();
	vector<bool>dp(n + 1);
	dp[0] = true;
	int wn = wordDict.size();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <wn ; j++)
		{
			if ( wordDict[j].length()<=i&&dp[i - wordDict[j].length()]  &&s.substr(i-wordDict[j].length(),wordDict[j].length()) == wordDict[j])
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n];
}
};
