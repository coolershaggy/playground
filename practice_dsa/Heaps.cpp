
#include "Heaps.h"
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
#include<queue>
#include <stack>
using namespace std;


static void priorityQ() {
	vector<int> nums = { 7, 10, 4, 3, 20, 15 };
	std::cout << "size of nums: " << nums.size() << endl;
	priority_queue<int> pq;
	for (int i = 0; i < nums.size(); i++)
	{
		pq.push(nums[i]);
	}
	std::cout << "Max PQ" << endl;
	while (!pq.empty())
	{
		std::cout << pq.top() << ' ';
		pq.pop();
	}std::cout << '\n';

	priority_queue<int, vector<int>, greater<int>> min_pq;
	std::cout << "Min PQ" << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		min_pq.push(nums[i]);
	}
	while (!min_pq.empty())
	{
		std::cout << min_pq.top() << ' ';
		min_pq.pop();
	}std::cout << '\n';


}

//kth smallest element -> max-heap
//kth largest element -> min-heap

// arr : given array
// k : find kth smallest element and return using this function
static int kthSmallest(vector<int>& arr, int k) {
	/*
	//this solution has TC of O(n*log(n))
	priority_queue<int, vector<int>, greater<int>> minq;
	for (int i=0; i< arr.size(); i++) {
		minq.push(arr[i]);
	}
	for (int i= 0; i< k-1; i++) {
		minq.pop();
	}
	return minq.top();
	*/

	//below solution has TC of O(n*log(k))
	//we add elements in max heap till k. and for next elements we compare it with top.
	//if element is smaller than top, we pop the top and add that element. return top at the end

	//Stop adding elements to the heap once it contains k elements and
	//then only adds new elements if they are smaller than the current k-th smallest element:


	std::cout << "size of nums: " << arr.size() << endl;
	priority_queue<int> pq;
	for (int i = 0; i < arr.size(); i++) {
		if (pq.size() < k) {
			pq.push(arr[i]);
		}
		else {
			if (arr[i] < pq.top()) {
				pq.pop();
				pq.push(arr[i]);
			}
		}
	}
	cout << pq.top();
	return pq.top();

}
