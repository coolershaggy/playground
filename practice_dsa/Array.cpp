#include "Array.h"

void Array::printVec(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int Array::peak(vector<int>& vec)
{
	int start = 0;
	int end = vec.size() - 1;
	int mid = (start + end) / 2;
	int res = 0;
	while (start < end)
	{
		if (vec[mid] < vec[mid + 1])
		{
			start = mid + 1;
		}
		else if (vec[mid] > vec[mid + 1])
		{
			end = mid;
		}

		mid = (start + end) / 2;
	}
	return mid;
}

//find the maximum sum of all subarrays of size K
//here it does not handle duplicates
//tried again now. Again this has too many boundary cases like 1,2,2, with k=2 and 4,4,4 with k=3 and so on.
//leetcode discussion also has less comments and not proper solution
long long Array::maximumSubarraySum(vector<int>& nums, int k) {
	set<int> mySet;
	long long maxSum = 0;
	long long ans = 0;
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		if (mySet.find(nums[i]) == mySet.end())
		{
			mySet.insert(nums[i]);
			maxSum += nums[i];
		}
	}
	long long sumOfSetElements = 0;
	if (nums.size() == k)
	{
		if (mySet.size() == k)
		{
			return maxSum;
		}
		else
		{
			for (int element : mySet) {
				sumOfSetElements += element;
			}
			return sumOfSetElements;
		}

	}
	else
	{
		for (int element : mySet) {
			sumOfSetElements += element;
		}
		//return sumOfSetElements;
	}
	long long windowSum = sumOfSetElements;

	for (int i = k; i < nums.size(); i++)
	{
		//remove outgoing element
		mySet.erase(nums[i - k]);
		//add incoming element
		mySet.insert(nums[i]);
		//calculate the sum of window if all are unique elements
		if (mySet.size() == k)
		{
			long long oldNum = nums[i - k];
			windowSum = windowSum + nums[i] - oldNum;
			ans = max(windowSum, maxSum);
		}
	}

	return ans;
}

//please read this. I spent quite some time on this and below solution is from answers on LC
long long Array::maximumSubarraySumAttemptlast(vector<int>& nums, int k)
{
	int i = 0;  //use i to keep track of start of window
	int j = 0;  //use j to travers in the window
	long long sum = 0, ans = 0;
	unordered_map<int, int> myMap;  //use map to keep track of unique elements

	while (j < nums.size())
	{
		myMap[nums[j]]++;
		sum += nums[j];
		if ((j - i + 1) < k) //if j is within window size, keep increasing till we reach window size
		{
			j++;
		}
		else
		{
			if (myMap.size() == k)  //this is for if all elements are unique then take the sum
			{
				ans = max(ans, sum);
			}
			//remove the element from sum and reduce its count in map
			sum -= nums[i];
			myMap[nums[i]]--;

			//remove element from map if its 0 otherwise it will be counted in size()
			if (myMap[nums[i]] == 0) {
				myMap.erase(nums[i]);
			}
			i++;
			j++;
		}
	}
	return ans;
}

int Array::subarraySum(vector<int>& nums, int k) {
	int i = 0, j = i + 1;
	int sum = 0, count = 0;

	while (j < nums.size())
	{


	}
	return count;
}

int Array::maxSubArray(vector<int>& nums) {
	int sum = 0;
	int maxi = INT_MIN;
	//bruteforce
	/*for (int i = 0; i < nums.size(); i++)
	{
		sum = 0;
		for (int j = i; j < nums.size();j++) {
			sum += nums[j];
			maxi = max(maxi, sum);
		}

	}*/

	//kadane's algo
	for (int i = 0; i < nums.size(); i++)
	{
		sum = max(nums[i], sum + nums[i]);
		maxi = max(maxi, sum);
	}
	//cout << "maxi: " << maxi << endl;
	return maxi;
}

//check solution.cpp for easy way
double Array::findMaxAverage(vector<int>& nums, int k) {
	double avg = 0;
	unordered_map<int, int> myMap;
	double i = 0;
	double j = 0;
	double sum = 0;
	double ans = std::numeric_limits<double>::lowest();
	if (nums.size() == 1)
	{
		double myDouble = static_cast<double>(nums[0]);
		return myDouble;
	}
	while (j < nums.size())
	{
		myMap[nums[j]]++;
		sum += nums[j];
		avg = sum / k;
		if ((j - i + 1) < k) //if j is within window size, keep increasing till we reach window size
		{
			j++;
		}
		else
		{
			//if (myMap.size() == k)  //this is for if all elements are unique then take the sum
			//{
			avg = sum / k;
			ans = max(ans, avg);
			//}
			//remove the element from sum and reduce its count in map
			sum -= nums[i];

			myMap[nums[i]]--;

			//remove element from map if its 0 otherwise it will be counted in size()
			if (myMap[nums[i]] == 0) {
				myMap.erase(nums[i]);
			}
			i++;
			j++;
		}
	}

	return ans;
}

bool Array::canBeEqual(vector<int>& target, vector<int>& arr) {
	vector<int> targetVector(1001); //check why we get runtime error on leetcode for 1000
	vector<int> arrVector(1001);

	for (int i : target) {
		targetVector[i]++;
	}
	for (int& i : arr) {
		arrVector[i]++;
	}
	if (targetVector == arrVector)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//this has more runtime
bool Array::canBeEqual_1(vector<int>& target, vector<int>& arr) {
//	this has more runtime as its 
//	unordered_map<int, int> targetMap;
//	unordered_map<int, int> arrMap;
//	for (auto x : target) {
//		targetMap[x]++;
//	}
//	for (auto x : arr) {
//		arrMap[x]++;
//	}
//	if (targetMap.size() == arrMap.size())
//	{
//		for (int i = 0; i < targetMap.size(); i++) 
//		{
//			if (targetMap[i] != arrMap[i])
//			{
//				return false;
//			}
//		}
//	}
//	else
//	{
//		return false;
//	}
	return true;
}

//get equilibrium point where left and right sum is equal
int Array::getEquilibrium(vector<int> &nums) {

	int res = 0;
	int totalSum = 0;
	int leftsum = 0;
	for (int num : nums) {
		totalSum += num;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		totalSum -= nums[i];
		if (leftsum == totalSum)
		{
			//cout << i << endl;
			return i;
		}
		leftsum += nums[i];
	}
	return 0;
}

//finding pivot of array. pivot is point by which array is rotated
int Array::findPivot(vector<int>& nums) {

	int start = 0;
	int end = nums.size() - 1;
	int mid = (start + end) / 2;
	//int mid = start + (end - start) / 2;

	while (start < end)
	{
		if (nums[mid] > nums[0]) {
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
		mid = (start + end) / 2;
	}
	cout << "Pivot: " <<mid << endl;
	return mid;
}
