#include "DynamicProgramming.h"

#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;

int DP::solveMaximumNonAdjacentSum(vector<int>& nums, int n) {
	// Base case: if n is less than 0, there are no elements to consider
	if (n < 0) {
		return 0;
	}

	// Including the current number, so move two places ahead
	int inc = solveMaximumNonAdjacentSum(nums, n - 2) + nums[n];
	// Not including the current number, so move only one place ahead
	int excl = solveMaximumNonAdjacentSum(nums, n - 1);

	// Return the maximum of including or excluding the current number
	return max(inc, excl);
}

int DP::solveMaximumNonAdjacentSumDP_Memo(vector<int>& nums, int n, vector<int>& dp) {
	// Base case: if n is less than 0, there are no elements to consider
	if (n < 0) {
		return 0;
	}
	//base case
	if (n == 0) {
		return nums[0];
	}

	//step-4: check if answer is already there in dp array for next iteration, if yes then return that answer
	if (dp[n] != -1) {
		return dp[n];
	}

	// Including the current number, so move two places ahead
	int inc = solveMaximumNonAdjacentSumDP_Memo(nums, n - 2, dp) + nums[n];

	// Not including the current number, so move only one place ahead
	int excl = solveMaximumNonAdjacentSumDP_Memo(nums, n - 1, dp);

	//step-2: save the answer in dp array befor returning
	dp[n] = max(inc, excl);

	//step-3: Return the maximum of including or excluding the current number
	return dp[n];
}

int DP::solveMaximumNonAdjacentSumDP_Tab(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 0);


	//base case
	dp[0] = nums[0];
	if (n > 1) dp[1] = max(nums[0], nums[1]); // Handle the case for the second element
	for (int i = 2; i < n; i++)
	{
		// Including the current number, so move two places ahead
		int inc = dp[i - 2] + nums[i];

		// Not including the current number, so move only one place ahead
		int excl = dp[i - 1] + 0;

		//step-2: save the answer in dp array befor returning
		dp[i] = max(inc, excl);
	}

	//step-3: Return the maximum of including or excluding the current number
	return dp[n - 1];
}

int DP::maximumNonAdjacentSum(vector<int>& nums) {
	int n = nums.size();
	//return solveMaximumNonAdjacentSum(nums, n-1);

	// with DP: Recurrsion + Memoization
	//step-1: init dp array with -1
	//vector<int> dp(n, -1);
	//return solveMaximumNonAdjacentSumDP_Memo(nums, n - 1, dp);
	return solveMaximumNonAdjacentSumDP_Tab(nums);
}


int DP::twinSum(vector<int> nums) {
	int twin_sum = 0;
	int ans = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		twin_sum = nums[i] + nums[size - 1 - i];
		ans = max(ans, twin_sum);
	}
	return ans;
}


//46. Permutations
//for unique elements
void DP::solvePermute(vector<int>& nums, vector<vector<int>>& answer, int index) {
	//base case
	if (index >= nums.size()) {
		answer.push_back(nums);
		return;
	}
	for (int i = index; i < nums.size(); i++) {
		swap(nums[index], nums[i]);
		solvePermute(nums, answer, index + 1);
		//wapis yetana reset to original karan bakichya calls sathi input original jayla pahije
		swap(nums[index], nums[i]);
	}

}

vector<vector<int>> DP::permute(vector<int>& nums) {
	vector<vector<int>> answer;
	int index = 0;
	solvePermute(nums, answer, index);
	return answer;
}
