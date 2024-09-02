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
   vector<string>ret;
void dfs(TreeNode* root,string path)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		path += to_string(root->val);
		ret.emplace_back(path);
	}
	else
	{
		path += to_string(root->val);
		path += "->";
		if(root->left)
		dfs(root->left, path);
		if(root->right)
		dfs(root->right, path);
	}
}
vector<string> binaryTreePaths(TreeNode* root) {
	dfs(root, "");
	return ret;
}
};
