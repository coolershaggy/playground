// practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
#include "PracticeString.h"
#include "LinkedList.h"
#include "Array.h"

//for tree traversal use queue
#include<queue>
#include <stack>


/**
 * Definition for a binary tree node.
 *  */
 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


using namespace std;

//note for passing 2D array as argument
//we need to pass atleast column size in function call. Otherwise complier will give error

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = matrix.size(); // row size
	int col = matrix[0].size(); //col size 
	int start = 0;
	int end = row*col-1;	//make sure to -1 if starting from 0
	int mid = start + (end - start) / 2; //to handle case of big numbers addition

	while (start <= end)
	{
		//mid is represented by matrix[i][j] -> matrix[mid/col][mid%col]
		//divide by col gives row number and mod(%) by col gives col number for any element in 2d array
		if (matrix[mid/col][mid%col] == target) {
			return true;
		}
		else if (target > matrix[mid/col][mid%col]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
	return false;

}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int count = 0;
	int total = m * n;

	int startRowIndex = 0;
	int startColIndex = 0;
	int endColIndex = n - 1;
	int endRowIndex = m - 1;

	vector<int> answer;

	while (count < total)
	{
		//for all loops check this condition before entering in loop "&& count < total"


		//print starting row from left to right
		for (int index = startColIndex; index <= endColIndex && count < total; index++)
		{
			answer.push_back(matrix[startRowIndex][index]);
			count++;
		}
		//increment starting row
		startRowIndex++;

		//print ending col from top to bottom
		for (int index = startRowIndex; index <= endRowIndex && count < total; index++)
		{
			answer.push_back(matrix[index][endColIndex]); 
			count++;
		}
		//decrement ending col
		endColIndex--;

		//print ending row from right to left
		for (int index = endColIndex; index >= startColIndex && count < total; index--)
		{
			answer.push_back(matrix[endRowIndex][index]);
			count++;
		}
		//decrement ending row
		endRowIndex--;

		//print starting col from bottom to top
		for (int index = endRowIndex; index >= startRowIndex && count < total; index--)
		{
			answer.push_back(matrix[index][startColIndex]);
			count++;
		}
		//increment starting col
		startColIndex++;

	}
	return answer;
}

vector<vector<int>> generateMatrix(int n) {

	int count = 1;
	int nSquare = n * n;

	int startRowIndex = 0;
	int startColIndex = 0;
	int endColIndex = n - 1;
	int endRowIndex = n - 1;


	vector<vector<int>> matrix(n,vector<int> (n,0));

	while (count <=nSquare)
	{
		//for all loops check this condition before entering in loop "&& count < total"


		//print starting row from left to right
		for (int index = startColIndex; index <= endColIndex && count <= nSquare; index++)
		{
			matrix[startRowIndex][index] = count;
			count++;
		}
		//increment starting row
		startRowIndex++;

		//print ending col from top to bottom
		for (int index = startRowIndex; index <= endRowIndex && count <= nSquare; index++)
		{
			matrix[index][endColIndex] = count;
			count++;
		}
		//decrement ending col
		endColIndex--;

		//print ending row from right to left
		for (int index = endColIndex; index >= startColIndex && count <= nSquare; index--)
		{
			matrix[endRowIndex][index] = count;
			count++;
		}
		//decrement ending row
		endRowIndex--;

		//print starting col from bottom to top
		for (int index = endRowIndex; index >= startRowIndex && count <= nSquare; index--)
		{
			matrix[index][startColIndex] =count;
			count++;
		}
		//increment starting col
		startColIndex++;

	}
	return matrix;
}

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

TreeNode* buildTree(TreeNode* root) {
	
	int val;
	cin >> val;
	root = new TreeNode(val);
	if (val == -1)
	{
		return NULL;
	}
	cout << "Enter for left of " << root->val<< " : " << endl;
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
				result= vec.back();
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

//1302. Deepest Leaves Sum
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

int main()
{
	//find peak of mountain
	/*
	vector<int> vec = {0,10,5,2};
	Array::printVec(vec);
	cout << Array::peak(vec) << endl;
	*/

	//equilibrium in array
	/*
	vector<int> nums = { 1,1,7,3,6,5,6 ,1};
	cout << Array::getEquilibrium(nums);
	*/

	//pivot in array
	/*
	vector<int> nums = { 8,10,17,1,3 };
	Array::findPivot(nums);
	*/

	//search in rotated array
	//find pivot and then based on element to search decide in which part to search

	//square root
	//square root with decimal

	//Linked List
	/*
	ListNode* firstNode = new ListNode(3);
	ListNode* head = firstNode;
	ListNode* tail = firstNode;
	LinkedList::print(head);
	LinkedList::insertAtHead(head, 5);
	LinkedList::print(head);
	LinkedList::insertAtHead(head, 7);
	LinkedList::print(head);
	LinkedList::insertAtHead(head, 5);
	LinkedList::print(head);
	LinkedList::insertAtTail(tail, 10);
	LinkedList::print(head);
	LinkedList::insertAtTail(tail, 11);
	LinkedList::print(head);
	LinkedList::insertAtTail(tail, 12);
	LinkedList::print(head);
	LinkedList::insertAt(head, tail, 3, 999);
	LinkedList::print(head);
	LinkedList::insertAt(head, tail, 0, 1000);
	LinkedList::print(head);
	LinkedList::insertAt(head, tail, 8, 1212);
	LinkedList::print(head);
	LinkedList::insertAtTail(tail, 6969);
	LinkedList::print(head);
	LinkedList::deleteNodeForTarget(head, 5);
	LinkedList::print(head);
	*/


	//LinkList operations
	/*
	//node initialization for LL operations
	ListNode* firstNode = new ListNode(18);
	ListNode* head = firstNode;
	ListNode* tail = firstNode;

	//LinkedList::insertAtHead(head, 5);
	//LinkedList::insertAtHead(head, 7);
	//LinkedList::insertAtHead(head, 5);
	LinkedList::insertAtTail(tail, 6);
	LinkedList::insertAtTail(tail, 10);
	LinkedList::insertAtTail(tail, 3);
	LinkedList::insertAtTail(tail, 22);
	LinkedList::insertAtTail(tail, 45);
	LinkedList::insertAtTail(tail, 66);
	LinkedList::insertAtTail(tail, 88);
	LinkedList::print(head);

	//traverse LL once to find count then use delete at positon
	LinkedList::removeNthFromEnd(head, 3);
	LinkedList::print(head);

	//delete node with given postion
	LinkedList::deleteNode(head, 2);
	LinkedList::print(head);

	//Revise this again whenever solving LL problem
	//reverseLL(head);
	//print(head);

	//deleteGivenNode(firstNode); -- incomplete


	//LinkedList::print(head);
	
	//insert GCD of two nodes in between them
	//LinkedList::insertGCD(head);
	//LinkedList::print(head);
	*/
	
	//GCD
	//cout << LinkedList::GCD(6,10);

	//vector<string> words = {"abc", "car", "ada", "racecar", "cool"};
	//char arr[5] = {'s','a','g','a','s'};
	//string inputString = "sagas";
	//checkPalindrome(inputString);
	//cout << firstPalindrome(words);

	//char input = 's';
	//cout << lowerToUppar(input);
	//char temp = 'Z';
	//cout << upparToLower(temp);

	//vector<int> target = { 1,2,3,4 };
	//vector<int> arr = { 1,2,3,7 };
	//cout << canBeEqual(target, arr);

	//string str = "   fly me   to   the moon  ";
	//cout << lengthOfLastWord(str);
	//str.push_back('$');
	//cout << str;

	//reverse a string
	//string str = "sagar pawar";
	//cout << reverseString(str) << endl;
	
	//reverseStringTillPostion
	//string str2 = "abcdefg";
	//cout << reverseStringTillPostion(str2,2) << endl;

	//string str = "  a    s   ";
	//cout << str << endl;
	//cout << trimString(str) << endl;

	/*
	//Revise this problem. 151. Reverse Words in a String
	//This took me a while to solve
	string str2 = "the sky is blue";
	cout << str2 << endl;
	cout << PracticeString::reverseWords(str2) << endl;
	*/

	//reverse the prefix. Find positon and then reverse till positon 
	//string word = "xyxzxe";
	//cout << reversePrefix(word, 'z');

	//string s = "Test1ng-Leet=code-Q!";
	//cout << reverseOnlyLetters(s);

	//do permutation in string
	//string compression: https://youtu.be/Wdjr6uoZ0e0?t=6276&si=0UpfDX27OKRHXsd9 need to revist the logic
	//


	//string str = "zzzsxxxxxxxxxxasdazxazazzazbdcaca";
	//cout << maxOccurenceOfChar(str);

	//int countS1[26] = { 0,1 };
	//int countS2[26] = { 0,1 };
	//cout << checkArrayEqual(countS1, countS2)<< endl;


	//string s1 = "ab";
	//string s2 = "eidbaooo";
	//cout <<checkInclusion(s1, s2) << endl;


	//vector<int> nums = { 1,2,2}; //  9,5,9,4,2,9
	//cout << maximumSubarraySum(nums,2);
	//cout << maximumSubarraySumAttemptlast(nums, 2);	//check this function for awesome answer

	//string str = "abbaca";
	//cout << removeDuplicates(str) << endl;
	
	/*
	*	understanding set to store unique elements
	set<int> mySet;
	set<int>::iterator *it;

	mySet.insert(16);
	mySet.insert(24);
	mySet.insert(7);
	mySet.insert(5);
	mySet.insert(2);
	mySet.insert(3);

	for (auto it = mySet.begin(); it != mySet.end(); it++)
	{
		 cout <<*it << endl;
	}
	cout << "size:" << mySet.size();
	*/

	//vector<int> nums = { 1,1,1 };
	//cout << subarraySum(nums, 2);
	//-2, 1, -3, 4, -1, 2, 1, -5, 4
	//vector<int> nums = { -1 };
	//cout << maxSubArray(nums);

	//vector<int> nums = { 8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891 };
    //cout << findMaxAverage(nums,93) << endl;


	/*
	ListNode* l1 = new ListNode(3);
	ListNode* headl1 = l1;
	ListNode* l2 = new ListNode(4);
	ListNode* headl2 = l2;

	insertAtHead(headl1, 4);
	insertAtHead(headl1, 2);


	insertAtHead(headl2, 6);
	insertAtHead(headl2, 5);



	//print(headl1);
	//print(headl2);


	ListNode* res = addTwoNumbersGPT(headl1, headl2);
	//print(res);
	*/

	/*
	string s = "sagas";
	cout << PracticeString::checkPalindrome(s);
	*/

	//vector<int> nums = { 5,0,1,2,3,4 };
	//vector<int> ans(nums.size());
	//for (int i = 0; i < nums.size(); i++)
	//{
	//	ans[i] = nums[nums[i]];
	//}
	//for (int i = 0; i < ans.size(); i++)
	//{
	//	cout << ans[i] << " ";
	//	
	//}

	//2D-Array search. Binary Search
	//vector<vector<int>> matrix = { {1, 3, 5, 7} ,{10, 11, 16, 20},{23, 30, 34, 60 } };
	//cout << searchMatrix(matrix, 69);

	//spiral print
	/*
	vector<vector<int>> matrix = { {1, 2, 3} ,{4, 5, 6},{7, 8, 9} };
	vector<int> result = spiralOrder(matrix);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	*/

	//generate spiral Matrix for given n. 1 -> n2 elements
	/*
	int n = 3;
	vector<vector<int>> resultmatrix = generateMatrix(n);
	for (int i = 0; i < resultmatrix.size(); i++)
	{
		for (int j = 0; j < resultmatrix.size(); j++)
		{
			cout << resultmatrix[i][j] << " ";
		}
		cout << endl;
	}*/

	//TODO
	//rotate image

	//spiral matrix iii
	//spiral inside out - imp
	//2D search ii

	//create your own class node for Linked List, Tree, etc
	
	//trees
	TreeNode* myroot = NULL;
	//input for copy paste
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	//3 9 -1 -1 20 15 -1 -1 7 -1 -1 
	//1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
	myroot = buildTree(myroot);
	//levelOrderTreeTraversal(myroot);
	//revereseLevelOrderTreeTraversal(root);
	
	vector<vector<int>> res = levelOrder(myroot);
	//vector<vector<int>> res = levelOrderBottom(myroot);

	//height of binary tree
	//int height = maxDepth(myroot);
	//cout << "height/depth: " << height;

	//useful for getting height in other traversal. optimized for other problems
	pair<int, int> mypair  = make_pair(12,99);
	//cout << mypair.first << " " << mypair.second << endl;
	
	//sum tree -> check where it is on LC
	//Diameter of Tree
	/*
	Height of Tree: https://practice.geeksforgeeks.org/pr...
	Diameter of Tree: https://practice.geeksforgeeks.org/pr...
	Balanced Tree or Not: https://practice.geeksforgeeks.org/pr...
	Tree Identical or Not:https://practice.geeksforgeeks.org/pr...
	Sum Tree or Not:https://practice.geeksforgeeks.org/pr...
	*/

	/*
	- (Done) - ZigZag Traversal: https://practice.geeksforgeeks.org/pr...
	- Boundary Traversal:https://practice.geeksforgeeks.org/pr...
	- Vertical Order Traversal:https://practice.geeksforgeeks.org/pr...
	- Top View:https://practice.geeksforgeeks.org/pr...
	- Bottom View:https://practice.geeksforgeeks.org/pr...
	- Right View:https://practice.geeksforgeeks.org/pr...
	- Left View:https://practice.geeksforgeeks.org/pr...
	- Diagonal Traversal:https://practice.geeksforgeeks.org/pr...
	*/

	zigzagLevelOrder(myroot);
}



