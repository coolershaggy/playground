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
#include "Trees.h"
#include "DynamicProgramming.h"
#include "Trie.h"
#include "Heaps.cpp"


using namespace std;

//note for passing 2D array as argument
//we need to pass atleast column size in function call. Otherwise complier will give error

class graph
{
private:
	vector<list<int>> adj;
	int vertices;
	
public:
	
	graph(int num) : vertices(num), adj(num)
	{
	}
	
	//unordered_map<int, list<int>> adj;
	
	list<int> vList;
	void makeEdge(int u, int v) {
		//adj[u].push_back(v);
		
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	void printEdges() {
		for (int i = 0; i < vertices; i++)
		{
			cout <<  "Vertex: " <<i << "-> ";
			for(int x: adj[i]) {
				cout << x << ",";
			}
			cout << endl;

		}
	}
private:

};


//N-Queen with 0 and 1 as representation - START

void addBoardToAns(vector<vector<int>>& answer, vector<vector<int>> &board, int n) {
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; i++)
		{
			temp.push_back(board[i][j]);
		}
	}
	answer.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
	int x = row;
	int y = col;

	//we are adding queens by columns so we will check only for previously added col position

	//same row
	while (y >= 0)
	{
		if (board[x][y] == 1) {
			return false;
		}
		y--;
	}
	//diagonal up
	while (y >= 0 && x >= 0)
	{
		if (board[x][y] == 1) {
			return false;
		}
		y--;
		x--;
	}
	//diagonal down
	while (y >= 0 && x>n)
	{
		if (board[x][y] == 1) {
			return false;
		}
		y--;
		x++;
	}

	//jar ithe paryant alo mhanje safe aahe
	return true;

}

void solveNqueen(int col, vector<vector<int>> &answer, vector<vector<int>> &board, int n) {
	//base case
	if (col == n) {
		//add current board positions to answer vector
		addBoardToAns(answer, board, n);
		return;
	}

	//solve for one case of first col
	//go for all rows in first col
	for (int row = 0; row < n; row++)
	{
		//check if its safe to place queen on this column
		if (isSafe(row, col, board, n)) {
			board[row][col] = 1;
			solveNqueen(col + 1, answer, board, n);
			board[row][col] = 0; //bracktrack if not the right position
		}
	}

}

vector<vector<int>> nQueens(int n)
{
	//create board, initialize it to N
	vector<vector<int>> board(n, vector<int>(n,0));
	vector<vector<int>> answer;
	//start with Column 0
	solveNqueen(0, answer, board, n);
	return answer;
}

//N-Queen with 0 and 1 as representation - END

//Sudoku solver --START

bool isSafeForSudoku(int row, int col, vector<vector<int>>& board, int val) {
	for (int i = 0; i < 9; i++)
	{
		//check all columns in row
		if (board[row][i] == val) {
			return false;
		}
		//check all rows in column
		if (board[i][col] == val) {
			return false;
		}
		//check 3*3 matrix
		if (board[row+i/3][col+i%3] == val) {
			return false;
		}
	}
	return true;

}

bool solveMySudoku(vector<vector<int>>& board) {
	// size of board. We know its 9 but still
	int size = board[0].size();

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			//0 means position is empty and we can start solving it for 0
			if (board[row][col] == 0) {
				for (int val = 1; val < 10; val++) {
					if (isSafeForSudoku(row, col, board, val)) {
						board[row][col] = val;
						bool nextPossibleSolution = solveMySudoku(board);
						if (nextPossibleSolution) {
							return true;
						}
						else
						{
							board[row][col] = 0;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<int>>& board) {
	bool canWeSolveIt = solveMySudoku(board);
}

bool isSafeForSudokuGPT(int row, int col, vector<vector<char>>& board, char val) {
	int n = board.size(); // Assuming the board is n x n and n is a perfect square.
	int subgridSize = sqrt(n); // Size of the small square, typically 3 for a 9x9 Sudoku.
	int startRow = row - row % subgridSize; // Starting index of the small square's row.
	int startCol = col - col % subgridSize; // Starting index of the small square's column.

	for (int i = 0; i < n; i++) {
		// Check all columns in the row
		if (board[row][i] == val) {
			return false;
		}
		// Check all rows in the column
		if (board[i][col] == val) {
			return false;
		}
	}
	// Check the 3x3 subgrid
	for (int i = 0; i < subgridSize; i++) {
		for (int j = 0; j < subgridSize; j++) {
			if (board[startRow + i][startCol + j] == val) {
				return false;
			}
		}
	}
	return true;
}

//Sudoku solver --END





int main()
{
	vector<int> nums = { 7, 10, 4, 3, 20, 15,1 };
	cout << DP::maximumNonAdjacentSum(nums) << endl;

	//trie

	Trie* t = new Trie();
	t->insert("hello");
	t->insert("world");
	cout << "Present or not: " << t->searchWord("hello") << endl;

	priorityQ();
	//vector<int> nums = { 7, 10, 4, 3, 20, 15,1 };
	//int k = 3;
	//kthSmallest(nums,k);

	//std::string word = "Hello World";
	//for (int i = 0; i < word.length(); i++)
	//{
	//	std::string sub = word.substr(i); // "ello"
	//	std::cout << sub << std::endl; // Outputs: ello
	//}
	


	//ListNode* firstNode = new ListNode(10);
	//ListNode* head = firstNode;
	//ListNode* tail = firstNode;
	//LinkedList::insertAtTail(tail, 1);

	//LinkedList::insertAtTail(tail, 13);

	//LinkedList::insertAtTail(tail, 6);

	//LinkedList::insertAtTail(tail, 9);

	//LinkedList::insertAtTail(tail, 5);

	//LinkedList::print(head);

	//ListNode* list2 = new ListNode(1000000);
	//ListNode* headL2 = list2;
	//ListNode* tailL2 = list2;
	//LinkedList::insertAtTail(tailL2, 1000001);
	//LinkedList::insertAtTail(tailL2, 1000002);

	//LinkedList::print(headL2);

	//mergeInBetween(firstNode, 3,4, list2);
	//LinkedList::print(head);

	//---------------------------------------

	//vector<int> nums = { 4,2,2,3 };

	//cout << twinSum(nums);
	// 
	//cout << maximumNonAdjacentSum(nums);
	//------------------------------------------------------------
	
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
	//string temp = "123A man, a plan, a canal: Panama";
	//cout << PracticeString::upparToLower(temp) << endl;
	//cout << PracticeString::removeNonAlphanumericAndToLower(temp) << endl;
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
	//TreeNode* myroot = NULL;
	//input for copy paste
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	//3 9 -1 -1 20 15 -1 -1 7 -1 -1 
	//1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
	//myroot = Trees::buildTree(myroot);
	//levelOrderTreeTraversal(myroot);
	//revereseLevelOrderTreeTraversal(root);
	
	//vector<vector<int>> res = levelOrder(myroot);
	//vector<vector<int>> res = levelOrderBottom(myroot);

	//height of binary tree
	//int height = maxDepth(myroot);
	//cout << "height/depth: " << height;

	//useful for getting height in other traversal. optimized for other problems
	//pair<int, int> mypair  = make_pair(12,99);
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

	//zigzagLevelOrder(myroot);

	//BST started from here

	//Inorder predecesor and sucsessor for Binary Tree

	//(Done) Validate BST : https://www.codingninjas.com/codestud...
	//(Done)Kth Smallest / Largest in BST : https://www.codingninjas.com/codestud...
	//(Done)LCA in BST : https://www.codingninjas.com/codestud...
	//-Inorder Predecessor / Successor : https ://www.codingninjas.com/codestud...
	//for this traverse the tree in inorder way and store it in array/vec. for given key, predecessor will be key-1 and successor will key+1
	//this can be optimized for space by using pair<predecessor, successor>

	//TODO: Trees and Binary Trees
	/*
	//Inorder predecesor and sucsessor for Binary Tree
	//-Boundary Traversal : https://practice.geeksforgeeks.org/pr...
	//-Vertical Order Traversal : https://practice.geeksforgeeks.org/pr...
	//-Top View : https://practice.geeksforgeeks.org/pr...
	//-Bottom View : https://practice.geeksforgeeks.org/pr...
	//-Right View : https://practice.geeksforgeeks.org/pr...
	//-Left View : https://practice.geeksforgeeks.org/pr...
	//-Diagonal Traversal : https://practice.geeksforgeeks.org/pr...

	*/
	//IMP Try once
	//- Largest BST Subtree: https://www.codingninjas.com/codestud...


	// backtracking
	/*vector<vector<string>> answer = { {"X..."},{".Y.."} };
	vector<string> temp;
	temp.push_back("A");
	temp.push_back("A");
	temp.push_back("A");
	temp.push_back("A");
	answer.push_back(temp);
	string s1 = answer[0][0];
	string s2 = answer[1][0];
	string s3 = answer[2][0];*/

	//answer for above situation required in N-Queen problem
	//use temp string to store values and push that string
	/*
	void addBoardToAns(vector<vector<string>>& answer, vector<vector<string>>& board, int n) {
		vector<string> temp;
		for (int i = 0; i < n; i++) {
			string row;
			for (int j = 0; j < n; j++) {
				row += board[i][j]; // Concatenate the characters of the row
			}
			temp.push_back(row); // Add the concatenated row string to the temp vector
		}
		answer.push_back(temp); // Add the temp vector representing the board to the answer
	}
	*/
	
	//cout << endl;


	//Graphs
	//graph g(5);
	//g.makeEdge(0, 1);
	//g.makeEdge(0, 2);
	//g.makeEdge(1, 0);
	//g.makeEdge(1, 2);
	//g.makeEdge(1, 3);
	//g.makeEdge(2, 0);
	//g.makeEdge(2, 1);
	//g.makeEdge(3, 1);

	//g.makeEdge(0,1);
	//g.makeEdge(0,2);
	//g.makeEdge(2,1);
	//g.makeEdge(1,3);

	//g.makeEdge(0, 1);
	//g.makeEdge(1, 3);
	//g.makeEdge(0, 2);
	//g.makeEdge(2, 4);

	//g.printEdges();
}



