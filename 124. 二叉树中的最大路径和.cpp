/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int fun(TreeNode* t,int&mx)
{
	int left, right;
	if (t->left == nullptr)
		left = 0;
	else
		left = max(0, fun(t->left, mx));
	if (t->right == nullptr)
		right = 0;
	else
		right = max(0, fun(t->right, mx));
	int cur = left + right + t->val;
	mx = max(mx, cur);
	return t->val+max(left,right);
}
int maxPathSum(TreeNode* root) {
	int mn = INT_MIN;
	fun(root, mn);
	return mn;
}
};
