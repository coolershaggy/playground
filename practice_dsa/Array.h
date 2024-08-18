#pragma once
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;
class Array
{
public:
	static void printVec(vector<int>& vec);
	static int peak(vector<int>& vec);
	static long long maximumSubarraySum(vector<int>& nums, int k);
	static long long maximumSubarraySumAttemptlast(vector<int>& nums, int k);
	static int subarraySum(vector<int>& nums, int k);
	static int maxSubArray(vector<int>& nums);
	static double findMaxAverage(vector<int>& nums, int k);
	static bool canBeEqual(vector<int>& target, vector<int>& arr);
	static bool canBeEqual_1(vector<int>& target, vector<int>& arr);

	static int getEquilibrium(vector<int>& nums);
	static int findPivot(vector<int>& nums);

	static bool searchMatrix(vector<vector<int>>& matrix, int target);
	static vector<int> spiralOrder(vector<vector<int>>& matrix);
	static vector<vector<int>> generateMatrix(int n);

};

