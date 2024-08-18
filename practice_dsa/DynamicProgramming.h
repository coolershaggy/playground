#pragma once

#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>
using namespace std;
class DP
{
public:
	static int solveMaximumNonAdjacentSum(vector<int>& nums, int n);
	static int solveMaximumNonAdjacentSumDP_Memo(vector<int>& nums, int n, vector<int>& dp);
	static int solveMaximumNonAdjacentSumDP_Tab(vector<int>& nums);
	static int maximumNonAdjacentSum(vector<int>& nums);

	static int twinSum(vector<int> nums);
	static void solvePermute(vector<int>& nums, vector<vector<int>>& answer, int index);
	static vector<vector<int>> permute(vector<int>& nums);
};

