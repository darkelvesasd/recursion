int gn;
int ret = 0;
vector<bool>vb(16);
void dfs(int k)
{
	if (k == gn + 1)
	{
		ret += 1;
		return;
	}
	for (int i = 1; i <= gn; i++)
	{
		if (vb[i] == false && (k % i == 0|| i% k == 0))
		{
			vb[i] = true;
			dfs(k + 1);
			vb[i] = false;
		}
	}
}
int countArrangement(int n) {
	gn = n;
	dfs(1);
	return ret;
}
