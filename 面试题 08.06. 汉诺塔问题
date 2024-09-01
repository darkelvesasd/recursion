class Solution {
public:
    void move(vector<int>& A, vector<int>& B, vector<int>& C,int n)
{
	if (n == 1)
	{
		int t = A.back();
		A.pop_back();
		C.emplace_back(t);
		return;
	}
	move(A, C, B,n-1);
	int t = A.back();
	A.pop_back();
	C.emplace_back(t);
	move(B, A, C,n-1);
}
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
	move(A, B, C, A.size());
}
};
