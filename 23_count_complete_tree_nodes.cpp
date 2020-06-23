/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/


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
private:
    void traverse(TreeNode* root, int& cnt) {
        if (root == nullptr)
            return;
        ++cnt;
        traverse(root->left, cnt);
        traverse(root->right, cnt);
    }
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        traverse(root, cnt);
        return cnt;
    }
};


// O(log(n)^2) solution - Exploiting the complete binary tree property
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = 0, rh = 0;
        TreeNode* lst = root, *rst = root;
        while (lst) {
            ++lh;
            lst = lst->left;
        }
        while (rst) {
            ++rh;
            rst = rst->right;
        }
        if (lh == rh) return (1 << rh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};