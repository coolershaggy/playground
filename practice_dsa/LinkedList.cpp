#include "LinkedList.h"
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;

void LinkedList::insertAtHead(ListNode*& head, int val)
{
	ListNode* newNode = new ListNode(val);
	newNode->next = head;
	head = newNode;
}

void LinkedList::insertAtTail(ListNode*& tail, int val)
{
	ListNode* newNode = new ListNode(val);
	tail->next = newNode;
	tail = newNode;
}

void LinkedList::print(ListNode*& head) {
	ListNode* temp = head;
	cout << "Printing LL: " << endl;
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::insertAt(ListNode*& head, ListNode*& tail, int pos, int val)
{
	ListNode* newNode = new ListNode(val);
	ListNode* temp = head;
	int count = 1;
	//if this is first position then its insert at head
	if (pos == 0)
	{
		insertAtHead(head, val);
		return;
	}
	while (count < pos - 1)
	{
		temp = temp->next;
		count++;
	}

	//insert at position
	newNode->next = temp->next;
	temp->next = newNode;

	//here we are inserting at the end/tail
	if (temp->next == NULL)
	{
		insertAtTail(tail, val);
		return;
	}
}

void LinkedList::deleteNode(ListNode*& head, int position)
{
	int count = 1;
	ListNode* current = head;
	ListNode* prev = NULL;
	if (position == 1)
	{
		ListNode* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		while (count < position && current->next != NULL)
		{
			prev = current;
			current = current->next;
			count++;
		}
		ListNode* temp = current;
		if (prev != NULL)
		{
			prev->next = current->next;
		}
		current = current->next;
		temp->next = NULL;
		delete temp;
	}
}

void LinkedList::deleteNodeForTarget(ListNode*& head, int target)
{
	//delete Node with value provided
	if (head == NULL)
	{
		return;
	}
	//if target is at head then keep deleting
	while (head != NULL && head->val == target)
	{
		ListNode* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	//at this point target is not at head
	ListNode* current = head;
	ListNode* prev = NULL;

	while (current != NULL) //to check till end of LL
	{
		if (current->val == target)	//check if target found
		{
			ListNode* temp = current; //create a temp pointer and point it to current so that we can delete it later
			if (prev != NULL) //ideally prev wont be null here but its better to check if this is null before using
			{
				prev->next = current->next;
			}
			current = current->next; // move current to next
			temp->next = NULL;
			delete temp;
		}
		else //else keep moving in LL till end 
		{
			prev = current;
			current = current->next;
		}
	}

}

void LinkedList::removeNthFromEnd(ListNode*& head, int n) {
	int count = 1;
	ListNode* current = head;
	ListNode* prev = NULL;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	int position = 1;
	int targetToDelete = count - n;
	LinkedList::deleteNode(head, targetToDelete);
	while (count - position != n)
	{
		position++;
	}

	ListNode* temp = current;
	if (prev != NULL)
	{
		prev->next = current->next;
	}
	//current = current->next;
	//temp->next = NULL;
	delete temp;
}

ListNode* LinkedList::reverseLL(ListNode*& head)
{
	ListNode* current = head;
	ListNode* prev = NULL;
	ListNode* forward = NULL;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	while (current != NULL)
	{
		forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	//remember this point
	head = prev; //current will be at NULL so we need to take previous pointer. 
	return head;
}

void LinkedList::deleteGivenNode(ListNode*& node) {

}

int LinkedList::GCD(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	while (a != b)
	{
		if (a > b) a = a - b;
		else b = b - a;
	}
	return a;
}

ListNode* LinkedList::insertGCD(ListNode*& head)
{
	ListNode* current = head;
	//this NULL conditions are very important for empty LL
	if (head == NULL or head->next == NULL)
	{
		return head;
	}

	while (current != NULL && current->next != NULL) //null case for forward
	{
		ListNode* forward = current->next;	//instead of creating forward outside, better to created it while traversing
		int result = GCD(current->val, forward->val);
		ListNode* temp = new ListNode(result);
		current->next = temp;
		temp->next = forward;
		current = forward;
		if (forward->next != NULL) // this condition improves runtime?
			forward = forward->next;

	}
}

ListNode* LinkedList::addTwoNumbers(ListNode* l1, ListNode* l2) {
	//l1 = [2,4,3], l2 = [5,6,4]
	//[7,0,8]


	ListNode* t1 = l1;
	ListNode* t2 = l2;
	ListNode* head = NULL;
	ListNode* temp = NULL;
	ListNode* newNode = NULL;
	int carry = 0;
	int remainder = 0, dividend = 0;
	//when both lls are equal
	while (t1 != NULL && t2 != NULL)
	{
		int sum = t1->val + t2->val + carry;
		if (sum > 9)
		{
			remainder = sum % 10;
			carry = sum / 10;
			newNode = new ListNode(remainder);
		}
		else
		{
			newNode = new ListNode(sum);
		}
		newNode->next = temp;
		temp = newNode;
		t1 = t1->next;
		t2 = t2->next;
	}
	if (t1 == NULL && t2 == NULL)
	{
		if (temp->val < 9)
		{
			carry = 0;
		}

	}
	while (t1 != NULL)
	{
		int sum = t1->val + carry;

		newNode = new ListNode(sum);
		if (sum > 9)
		{
			remainder = sum % 10;
			carry = sum / 10;
			newNode = new ListNode(remainder);
		}
		else
		{
			newNode = new ListNode(sum);
		}
		newNode->next = temp;
		temp = newNode;
		t1 = t1->next;
	}

	while (t2 != NULL)
	{
		int sum = t2->val + carry;
		newNode = new ListNode(sum);
		if (sum > 9)
		{
			remainder = sum % 10;
			carry = sum / 10;
			newNode = new ListNode(remainder);
		}
		else
		{
			newNode = new ListNode(sum);
		}
		newNode->next = temp;
		temp = newNode;
		t2 = t2->next;
	}
	if (carry != 0)
	{
		newNode = new ListNode(carry);
		newNode->next = temp;
		temp = newNode;
	}
	//print(temp);
	head = reverseLL(temp);
	//print(head);
	return head;
}

//read this again
ListNode* LinkedList::addTwoNumbersGPT(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(0); // Dummy head to simplify adding nodes
	ListNode* current = dummyHead;
	int carry = 0;

	while (l1 != NULL || l2 != NULL || carry != 0) {
		int sum = carry;
		if (l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}
		carry = sum / 10; // Calculate carry for the next iteration
		current->next = new ListNode(sum % 10); // Create a new node with the remainder
		current = current->next; // Move to the next node
	}

	ListNode* head = dummyHead->next; // The real head of the result list
	delete dummyHead; // Delete the dummy head node
	return head; // Return the head of the result list
}

