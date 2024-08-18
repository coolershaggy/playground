#include "Trees.h"
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;

TreeNode* Trees::buildTree(TreeNode* root) {

	int val;
	cin >> val;
	root = new TreeNode(val);
	if (val == -1)
	{
		return NULL;
	}
	cout << "Enter for left of " << root->val << " : " << endl;
	root->left = buildTree(root->left);
	cout << "Enter for right:" << root->val << " : " << endl;
	root->right = buildTree(root->right);
	return root;
}

void levelOrderTreeTraversal(treeNode* root)
{
	queue<treeNode*> q;
	q.push(root);
	q.push(NULL); //This is separator for level

	while (!q.empty())
	{
		treeNode* temp = q.front();
		q.pop();
		if (temp == NULL)	//purana level complete traverse hogaya hai
		{
			cout << endl; //print new line when level completes
			if (!q.empty()) //queue still has child nodes 
			{
				q.push(NULL);
			}
			//if queue is empty then do nothing. Done printing
		}
		else
		{
			cout << temp->data << " "; //print if temp is not null
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}

}

void revereseLevelOrderTreeTraversal(treeNode* root)
{
	queue<treeNode*> q;
	q.push(root);
	q.push(NULL); //This is separator for level
	vector<vector<int>> ans;
	vector<int> res;
	while (!q.empty())
	{
		treeNode* temp = q.front();
		q.pop();
		if (temp == NULL)	//purana level complete traverse hogaya hai
		{
			ans.push_back(res);
			cout << endl; //print new line when level completes
			res.clear();
			if (!q.empty()) //queue still has child nodes 
			{
				q.push(NULL);
			}
			//if queue is empty then do nothing. Done printing
		}
		else
		{

			cout << temp->data << " "; //print if temp is not null
			res.push_back(temp->data);
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}

vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> ans;
	//this is to check if given tree is empty
	if (root == NULL) //not giving this condition was giving me Memory execeeded error on LC. So remember this
	{
		return ans;
	}
	q.push(root);
	q.push(NULL); //This is separator for level

	vector<int> res;
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		if (temp == NULL)	//purana level complete traverse hogaya hai
		{
			ans.push_back(res);
			cout << endl; //print new line when level completes
			res.clear();
			if (!q.empty()) //queue still has child nodes 
			{
				q.push(NULL);
			}
			//if queue is empty then do nothing. Done printing
		}
		else
		{
			cout << temp->val << " "; //print if temp is not null

			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
			res.push_back(temp->val);
		}

	}
	return ans;
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> ans;
	//this is to check if given tree is empty
	if (root == NULL) //not giving this condition was giving me Memory execeeded error on LC. So remember this
	{
		return ans;
	}
	q.push(root);
	q.push(NULL); //This is separator for level

	vector<int> res;
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		if (temp == NULL)	//purana level complete traverse hogaya hai
		{
			ans.push_back(res);
			cout << endl; //print new line when level completes
			res.clear();
			if (!q.empty()) //queue still has child nodes 
			{
				q.push(NULL);
			}
			//if queue is empty then do nothing. Done printing
		}
		else
		{

			cout << temp->val << " "; //print if temp is not null
			res.push_back(temp->val);
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == NULL && q != NULL) {
		return false;
	}
	if (p != NULL && q == NULL) {
		return false;
	}
	if (p == NULL && q == NULL) {
		return true;
	}
	//his condition for same tree
	if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val)) {
		return true;
	}
	return false;
}

bool isSameTreeForMirror(TreeNode* p, TreeNode* q) {
	if (p == NULL && q != NULL) {
		return false;
	}
	if (p != NULL && q == NULL) {
		return false;
	}
	if (p == NULL && q == NULL) {
		return true;
	}
	//tweak this condition for mirror tree
	if (isSameTreeForMirror(p->left, q->right) && isSameTree(p->right, q->left) && (p->val == q->val)) {
		return true;
	}
	return false;
}

bool isSymmetric(TreeNode* root) {
	if (root->left == NULL && root->right == NULL) {
		return root;
	}
	TreeNode* p = root->left;
	TreeNode* q = root->right;
	return isSameTreeForMirror(p, q);
}

int maxDepth(TreeNode* root) {
	//base case
	if (root == NULL)
	{
		return 0;
	}
	//recursive calls

	int leftHeight = maxDepth(root->left); //on LC storing these in variables results wrong answer
	int rightHeight = maxDepth(root->right); //on LC storing these in variables results wrong answer

	//processing
	int answer = max(leftHeight, rightHeight) + 1;

	//on LC this is how I need to submit. In single line recursive call and removing above left/right height variables
	//int answer = max(maxDepth(root->left), maxDepth(root->right)) + 1;

	return answer;
}

//check if tree is balanced or not
//depth of two subtree of every node never differs by more than one i.e. <=1
pair<bool, int> isBalancedFast(TreeNode* root) {

	//base case
	if (root == NULL)
	{
		pair<bool, int> resultPair = make_pair(true, 0);
		return resultPair;
	}
	//recursive calls
	pair<bool, int> Left = isBalancedFast(root->left);
	pair<bool, int> Right = isBalancedFast(root->right);
	//if I dont store these in below vairable I get wrong answer on LC. Not sure why
	bool lAns = Left.first;
	bool rAns = Right.first;

	int height = abs(Left.second - Right.second) + 1;// make sure we add this one for calulating height. 

	bool diff = height <= 1;

	pair<bool, int> answer;
	answer.second = max(Left.second, Right.second); //caluclate max height
	if (lAns && rAns && diff)
	{
		answer.first = true;
	}
	else {
		answer.first = false;
	}

	return answer;
}

bool isBalanced(TreeNode* root) {

	//base case
	return isBalancedFast(root).first;
}

//sum of left leaf nodes
int sum = 0;
int sumOfLeftLeaves(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
	{
		sum += root->left->val;
	}
	sumOfLeftLeaves(root->left);
	sumOfLeftLeaves(root->right);
	return sum;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;

	bool leftToRight = true;
	if (root == NULL)
	{
		return result;
	}
	queue<TreeNode*> queueForLevel;
	queueForLevel.push(root);

	while (!queueForLevel.empty())
	{

		int size = queueForLevel.size();
		vector<int> answerAtLevel(size);//size is imp for initialization

		for (int i = 0; i < size; i++)
		{
			TreeNode* front = queueForLevel.front();
			queueForLevel.pop();
			//normal flow or reverse?
			//we can use different logic as well to reverse this result like reveresing array based on the level/some count
			int index = (leftToRight) ? i : size - i - 1;
			answerAtLevel[index] = front->val;

			if (front->left)
			{
				queueForLevel.push(front->left);
			}
			if (front->right)
			{
				queueForLevel.push(front->right);
			}
		}
		leftToRight = !leftToRight;
		result.push_back(answerAtLevel);
	}
	return result;

}

//1302. Deepest Leaves Sum
//memorize this. This is classic ex for level order traveral variation

int deepestLeavesSum(TreeNode* root) {
	vector<int> vec;
	int result = 0;

	if (root == NULL)
	{
		return result;
	}
	queue<TreeNode*> levelQueue;
	levelQueue.push(root);

	while (!levelQueue.empty()) {
		int size = levelQueue.size();	//calculate size of queue
		int sumAtLevel = 0;	//initilize level wise operation

		//do processing for items in queue and push next childs
		for (int i = 0; i < size; i++) {	//make sure this loop is till size and not size-1
			TreeNode* temp = levelQueue.front();	//get first element of queue
			//pop front of queue
			levelQueue.pop();

			//here we are calculation sum at each level
			sumAtLevel += temp->val;

			//check if current node(temp) has any left or right leaf. If yes, then push in queue for processing
			if (temp->left)
			{
				levelQueue.push(temp->left);
			}
			if (temp->right)
			{
				levelQueue.push(temp->right);
			}
		}
		//here one level is traversed. Current level results can be used for answer

		vec.push_back(sumAtLevel);
	}
	//last value pushed in vector will be sum of last level. Which is our answer
	result = vec.back();
	return result;
}

//IMP below
//Path Sum II
//here I am passing path as pass by reference(&) so single copy is made. Need to pop it everytime result is not found
//i can avoid that by passing pass by value as well and removing call for pop
void solvePathSum(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& answer) {
	if (root == NULL) {
		return;
	}
	path.push_back(root->val);

	//base case
	//on leaf node we need to check if updated targetSum minus that node value is 0 or not.
	//if it is zero then we can recursively check pervious nodes if they add up to targetSum
	if (root->left == NULL && root->right == NULL && (targetSum - root->val == 0)) {
		answer.push_back(path);
	}
	solvePathSum(root->left, targetSum - root->val, path, answer);
	solvePathSum(root->right, targetSum - root->val, path, answer);
	path.pop_back(); //only in case of if pass by reference is used
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> answer;
	vector<int> path;
	solvePathSum(root, targetSum, path, answer);
	return answer;
}

//437. Path Sum III
void solvePathSumIII(TreeNode* root, int targetSum, vector<int> path, int& count) {
	long long sum = 0;
	if (root == NULL) {
		return;
	}
	path.push_back(root->val);
	solvePathSumIII(root->left, targetSum, path, count);
	solvePathSumIII(root->right, targetSum, path, count);
	int size = path.size();
	//start from end of vector as that has most recent node and we need sum from any node
	for (int i = size - 1; i >= 0; i--) {
		sum += path[i];
		if (sum == targetSum) {
			count++;
		}
	}
}
int pathSumIII(TreeNode* root, int targetSum) {
	int count = 0;
	vector<int> path;
	solvePathSumIII(root, targetSum, path, count);
	return count;
}

//1161. Maximum Level Sum of a Binary Tree
int maxLevelSum(TreeNode* root) {
	int answer = 0;
	pair<int, int> myPair;
	vector<pair<int, int>> vec;
	if (root == NULL) {
		return 0;
	}
	queue<TreeNode*> q;
	q.push(root);
	int level = 1;
	while (!q.empty()) {
		int size = q.size();
		int levelSum = 0;
		for (int i = 0; i < size; i++) {  //make sure this loop is till size and not size-1
			TreeNode* temp = q.front();
			q.pop();
			levelSum += temp->val;
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
		myPair = make_pair(levelSum, level);
		vec.push_back(myPair);
		level++;    //make sure to increment level
	}
	//using custom sort expression for pair to sort with first value of pair where my levelSum is.
	sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.first > b.first; });
	//returing level which is at second of pair for largest sum
	return vec[0].second;
}

//2583. Kth Largest Sum in a Binary Tree
long long kthLargestLevelSum(TreeNode* root, int k) {
	long long answer = 0;
	vector<long long> vec;
	if (root == NULL) {
		return NULL;
	}
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		long long levelSum = 0;
		for (int i = 0; i < size; i++) {  //make sure this loop is till size and not size-1
			TreeNode* temp = q.front();
			q.pop();
			levelSum += temp->val;
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
		vec.push_back(levelSum);
	}
	sort(vec.rbegin(), vec.rend());
	if (vec.size() < k) {
		return -1;
	}
	return vec[k - 1];
}

//199. Binary Tree Right Side View
vector<int> rightSideView(TreeNode* root) {
	vector<int> answer;
	if (!root) {
		return answer;
	}
	queue<TreeNode*> levelQueue;
	levelQueue.push(root);

	while (!levelQueue.empty()) {
		int size = levelQueue.size();
		for (int i = 0; i < size; i++) {
			TreeNode* temp = levelQueue.front();
			levelQueue.pop();
			//last element in queue
			if (i == size - 1) {
				answer.push_back(temp->val);
			}
			if (temp->left) {
				levelQueue.push(temp->left);
			}
			if (temp->right) {
				levelQueue.push(temp->right);
			}
		}
	}
	return answer;
}

/*
int deepestLeavesSum(TreeNode* root) {
	vector<int> vec;
	int result = 0;

	if (root == NULL)
	{
		return result;
	}
	queue<TreeNode*> levelQueue;
	levelQueue.push(root);

	while (!levelQueue.empty()) {
		int size = levelQueue.size();	//calculate size of queue
		int sumAtLevel = 0;	//initilize level wise operation

		//do processing for items in queue and push next childs
		for (int i = 0; i < size; i++) {
			TreeNode* temp = levelQueue.front();	//get first element of queue
			//pop front of queue
			levelQueue.pop();

			//here we are calculation sum at each level
			sumAtLevel += temp->val;

			//check if current node(temp) has any left or right leaf. If yes, then push in queue for processing
			if (temp->left)
			{
				levelQueue.push(temp->left);
			}
			if (temp->right)
			{
				levelQueue.push(temp->right);
			}
		}
		//here one level is traversed. Current level results can be used for answer

		vec.push_back(sumAtLevel);
	}
	//last value pushed in vector will be sum of last level. Which is our answer
	result = vec.back();
	return result;
}
*/

//623. Add One Row to Tree
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
	if (depth == 1) {
		TreeNode* newNode = new TreeNode(val);
		newNode->left = root;
		root = newNode;
	}
	queue<TreeNode*> q;
	q.push(root);
	int level = 0;
	while (!q.empty()) {
		level++;
		int size = q.size();
		//break one level before where we want to insert level
		if (level == depth - 1) break;

		for (int i = 0; i < size; i++) {
			TreeNode* temp = q.front();
			q.pop();
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}

	}
	//now we insert new level with val here
	//get remaining items in the queue which hold remaining tree
	int size_after_break = q.size();
	while (size_after_break--) {
		TreeNode* current = q.front();
		q.pop();
		//creating new nodes with given val
		//this new node will be added to left and right of current node
		TreeNode* newLeft = new TreeNode(val);
		TreeNode* newRight = new TreeNode(val);
		newLeft->left = current->left;
		current->left = newLeft;    //current chya left madhe newleft

		newRight->right = current->right;
		current->right = newRight; //cuurent chya right madhe new right

	}
	//return root
	return root;
}

//BST problems from here

//700. Search in a Binary Search Tree
TreeNode* searchBST(TreeNode* root, int val) {
	//recursive way
	/*
	if(root == NULL){
		return NULL;
	}
	if (val == root->val) {
		return root;
	}
	else if (val < root->val) {
		return searchBST(root->left, val);
	}
	else{
		return searchBST(root->right, val);
	}
	*/

	//iterative way
	if (root == NULL) {
		return NULL;
	}
	TreeNode* temp = root;

	while (temp != NULL) {
		if (val == temp->val) {
			return temp;
		}
		else if (temp->val > val) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return NULL;
}

TreeNode* maxNode(TreeNode* root) {
	if (root == NULL) {
		return root;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}
TreeNode* minNode(TreeNode* root) {
	if (root == NULL) {
		return root;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

//450. Delete Node in a BST
TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL) {
		return root;
	}
	if (root->val == key) {
		//0 child
		if (root->left == NULL && root->right == NULL) {
			delete root;    //free the root. as its last node
			return NULL;    //Return NULL
		}
		//1 child 
		//left child
		if (root->left != NULL && root->right == NULL) {
			TreeNode* temp = root->left;
			delete root;
			return temp;

		}
		//right child
		if (root->left == NULL && root->right != NULL) {
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		//two child
		if (root->left != NULL && root->right != NULL) {
			//right se min value leke aao
			int minValueFromRightSubtree = minNode(root->right)->val;
			//current root me mini wala data copy karlo
			root->val = minValueFromRightSubtree;

			//ab humne right se min value lai hai to delete bhi right me karenge
			root->right = deleteNode(root->right, minValueFromRightSubtree);
			return root;
		}
	}
	else if (root->val > key) {
		root->left = deleteNode(root->left, key);
		return root;
	}
	else {
		root->right = deleteNode(root->right, key);
		return root;
	}

	return root;

}

//98. Validate Binary Search Tree
bool isValidBSTSolve(TreeNode* root, long long min, long long max) {
	if (root == NULL) {
		return true;
	}
	if (root->val > min && root->val < max)
	{
		//at this point one is valid, we need to check this recursively for remaining
		//check remaining tree here.

		//here save answer to variable and check both condition
		bool leftAns = isValidBSTSolve(root->left, min, root->val);
		bool rightAns = isValidBSTSolve(root->right, root->val, max);
		if (leftAns && rightAns) {
			return true;
		}
	}
	else {
		//if we come at this point then its not valid BST, return false
		return false;
	}
	return false;
}
bool isValidBST(TreeNode* root) {
	//use -infinity to +infinity to compare, 
	//here it is max and min range of long long int
	//question has given range of node value so use wider range
	//limits: https://cplusplus.com/reference/climits/
	long long min = LLONG_MIN, max = LLONG_MAX;
	return isValidBSTSolve(root, min, max);
}

//230. Kth Smallest Element in a BST
void inorderTraverse(TreeNode* root, vector<int>& ans) {
	if (root == NULL) {
		return;
	}
	inorderTraverse(root->left, ans);
	ans.push_back(root->val);
	inorderTraverse(root->right, ans);
	// one more tweak in inordertraversal to get answer
	/*
	if(root == NULL) {
	return -1;
	}
	//L
	int left = solve(root->left, count, k);
	if(left!=-1){
	return;
	}
	//N
	if(count==k) return root->data;

	//R
	return solve(root->right,count,k)
	*/
}
int kthSmallest(TreeNode* root, int k) {
	vector<int> ans;
	//traverser in-order and result is already sorted. return element from start
	inorderTraverse(root, ans);
	//sort(ans.begin(), ans.end());
	return ans[k - 1];
}


//235. Lowest Common Ancestor of a Binary Search Tree
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
	//if p and q are greater than root then we need to go to right subtree
	if (root->val < p->val && root->val < q->val) {
		return lowestCommonAncestorBST(root->right, p, q);  //make sure we return from this recursive call
	}

	//else left subtree we need to go to left subtree
	if (root->val > p->val && root->val > q->val) {
		return lowestCommonAncestorBST(root->left, p, q);   //and this call as well
	}

	//at this point p> root and q <root or vice versa, in both the case they have common ancestor 
	return root;
}


//1382. Balance a Binary Search Tree
TreeNode* makeBalancedBST(TreeNode* root, int start, int end, vector<int>& ans) {
	//base case
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	//create root as mid and use recursion for creating left and right subtree 
	TreeNode* newRoot = new TreeNode(ans[mid]);
	newRoot->left = makeBalancedBST(newRoot->left, start, mid - 1, ans);
	newRoot->right = makeBalancedBST(newRoot->right, mid + 1, end, ans);
	return newRoot;

}
//traverse inorder and get sorted array
//create root as mid and use recursion for creating left and right subtree 
TreeNode* balanceBST(TreeNode* root) {
	//traverse inorder and get sorted array
	vector<int> ans;
	inorderTraverse(root, ans);

	//apply Binary search to create tree
	int start = 0;
	int end = ans.size() - 1;
	return makeBalancedBST(root, start, end, ans);
}

//1008. Construct Binary Search Tree from Preorder Traversal
TreeNode* solveBstFromPreorder(vector<int>& preorder, int min, int max, int& index) {
	//base case
	if (index >= preorder.size()) {
		return NULL;
	}
	//check if value of vector are within range
	if (preorder[index] < min || preorder[index] >max) {
		return NULL;
	}
	TreeNode* root = new TreeNode(preorder[index++]);   //increment index for preorder vector for next recursive call
	//INT_MIN ... root->val....INT_MAX. something like this
	root->left = solveBstFromPreorder(preorder, min, root->val, index);
	root->right = solveBstFromPreorder(preorder, root->val, max, index);
	return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
	int min = INT_MIN;
	int max = INT_MAX;
	int index = 0;
	return solveBstFromPreorder(preorder, min, max, index);
}

//701. Insert into a Binary Search Tree
TreeNode* insertIntoBST(TreeNode* root, int val) {
	if (root == NULL) {
		root = new TreeNode(val);
		return root;
	}
	if (val < root->val) {
		root->left = insertIntoBST(root->left, val);
	}
	else {
		root->right = insertIntoBST(root->right, val);
	}
	return root;
}
