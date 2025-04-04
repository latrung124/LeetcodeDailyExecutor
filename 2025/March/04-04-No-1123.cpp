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
#include <bits/stdc++.h>

using namespace std;

struct TreeNode;
class Solution {
    public:
        // DFS function that returns the depth and LCA node
        pair<int, TreeNode*> dfs(TreeNode* node) {
            if (!node) return {0, nullptr};  // Base case
            
            auto [leftDepth, leftLCA] = dfs(node->left);
            auto [rightDepth, rightLCA] = dfs(node->right);
            
            if (leftDepth == rightDepth) {
                return {leftDepth + 1, node};  // Current node is LCA of deepest leaves
            } else if (leftDepth > rightDepth) {
                return {leftDepth + 1, leftLCA};  // Return deeper subtree’s LCA
            } else {
                return {rightDepth + 1, rightLCA};
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;  // Extract LCA from DFS result
        }
    };
    