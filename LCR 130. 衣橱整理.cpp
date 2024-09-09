class Solution {
public:
 int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1};
int m, n,val,ret;
bool vb[100][100];
void dfs(int a,int b)
{
	ret++;
	vb[a][b] = true;
	for (int k = 0; k < 4; k++)
	{
		int x = dx[k] + a;
		int y = dy[k] + b;
		int sum = 0;
		int xt = x;
		int yt = y;
		while (xt)
		{
			sum += xt % 10;
			xt /= 10;
		}
		while (yt)
		{
			sum += yt % 10;
			yt /= 10;
		}
		if (x >= 0 && x < m && y >= 0 && y < n && sum <= val && vb[x][y] == false)
		{
			dfs(x, y);
		}
	}
}
int wardrobeFinishing(int a, int b, int cnt) {
	m = a;
	n = b;
	val = cnt;
	dfs(0, 0);
	return ret;
}
};
