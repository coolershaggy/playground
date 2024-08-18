#pragma once
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LinkedList
{
public:
	static void insertAtHead(ListNode*& head, int val);
	static void insertAtTail(ListNode*& tail, int val);
	static void print(ListNode*& head);
	static void insertAt(ListNode*& head, ListNode*& tail, int pos, int val);
	static void deleteNode(ListNode*& head, int position);
	static void deleteNodeForTarget(ListNode*& head, int target);
	static void removeNthFromEnd(ListNode*& head, int n);
	static ListNode* reverseLL(ListNode*& head);
	static void deleteGivenNode(ListNode*& node);
	static int GCD(int a, int b);
	static ListNode* insertGCD(ListNode*& head);
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	static ListNode* addTwoNumbersGPT(ListNode* l1, ListNode* l2);

	static ListNode* middleNode(ListNode* head);



};

