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
 int ret = INT_MIN;
int tk = -1;
int kthSmallest(TreeNode* root, int k) {
	if (tk == -1)
	{
		tk = k;
	}
	if (root==nullptr)
	{
		return INT_MIN;
	}
	int l=kthSmallest(root->left, k);
	if (l != INT_MIN)
	{ 
		return ret;
	}
	if (--tk == 0)
	{
		ret = root->val;
		return ret;
	}
	int r = kthSmallest(root->right, tk);
		return ret;
}
};
