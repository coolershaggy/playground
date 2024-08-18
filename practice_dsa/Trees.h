#pragma once
#include<map>
#include <unordered_map>
#include <string>
#include<set>
#include <vector>
//for tree traversal use queue
#include<queue>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node. 
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class treeNode {
public:
	int data;
	treeNode* left;
	treeNode* right;

	treeNode(int val) {
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};


class Trees
{
public:
	static TreeNode* buildTree(TreeNode* root);
};





