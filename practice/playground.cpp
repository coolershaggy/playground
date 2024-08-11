// playground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include<set>
using namespace std;

//print array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVec(vector<int> vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

//swap function
void swapNumbers(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Swap alternate elements
void swapAlt(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size) {
            swapNumbers(arr[i], arr[i + 1]);
            swap(arr[i], arr[i + 1]);
        }
    }
}
//find unique for 2m+1
void printUnique(int arr[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res =  res xor arr[i];
    }
    cout << res << endl;
}

void print2Unique(int arr[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res = res xor arr[i];
    }
    int rbit = res & -res;
    int u1=0,u2=0;

    for (int i = 0; i < size; i++)
    {
        if (rbit&arr[i]) {
            u1 = u1 ^ arr[i];
        }
        else {
            u2 = u2 ^ arr[i];
        }
    }
    cout << "u1 and u2: " << u1 << " " << u2 << endl;
}

void printVec(vector<int> & vec) {
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int clearBit(int num, int i)
{

    // Create the mask for the ith
    // bit unset
    int mask = ~(1 << i);

    // Return the updated value
    return num & mask;
}

vector<int> firstOcc(vector<int>& nums, int target) {
    vector<int> ansF;
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
    //first
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            //found
            ansF.push_back(mid);
            end = mid - 1;
        }
        else if ( target < nums[mid])
        {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ansF;
}

vector<int> lastOcc(vector<int>& nums, int target) {
    vector<int> ansL;
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
    //first
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            //found
            ansL.push_back(mid);
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ansL;
}

bool isSorted(int arr[], int n)
{
    /* runner
    int arr[] = {1,2,3,4,5};
    int ans = isSorted(arr, 5);
    if (ans)
    {
        cout << "Array is Sorted";
    }
    */

    //base case
    if (n == 0 or n == 1)
        return true;
    
    //processing
    if (arr[0] > arr[1])
        return false;

    //recursion call
    return isSorted(arr+1,n-1);
}

int findPivotGPT(vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] > nums[end])
        {
            // Pivot is in the right half
            start = mid + 1;
        }
        else
        {
            // Pivot is in the left half or at mid
            end = mid;
        }
    }

    // At the end of the loop, start == end and points to the pivot
    cout << "Pivot: " << start << " Element: " << nums[start] << endl;
    return start;
}

int findPivot(vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;

    while (start < end)
    {
        if (nums[mid] > nums[end])
        {
            start = mid + 1;
        }
        else 
        {
            end = mid;
        }
        if (nums[mid] == nums[start])
        {
            start++;
        }
        if (nums[mid] == nums[end]) end--;
        
        mid = (start + end) / 2;
    }
    return start;


}

int binarySearchInRotated(vector<int>& nums, int& s, int& e, int &target)
{
    int start = s;
    int end = e;
    
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

void solve(vector<char>& s, int& i, int& j)
{
    if (i > j)
        return;
    swap(s[i], s[j]);
    i++;
    j--;
    solve(s, i, j);
}
//rotate array
void rotate(vector<int>& nums, int k) {
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}
int main()
{
    /*
    int eArray[6] = { 1,2,3,4,5,6};
    swapAlt(eArray, 6);
    printArr(eArray, 6);

    int oArray[5] = { 1,2,3,4,5};
    swapAlt(oArray, 5);
    printArr(oArray, 5);

    int x = 5;
    int y = 80;
    swapNumbers(x,y);
    cout << "x: " << x << " y:" << y << endl;

    int uniArr[5] = { 1,2,2,1,89 };
    printUnique(uniArr,5);
    */

    //cout << temp << " ";
    //cout << "Count :" << count << endl;
    //int arr1[6] = { 1,2,2,1,3,5 };
    //print2Unique(arr1, 6);

    /*
    // Sample array
    std::vector<int> arr3 = { 1,2,2,1,1,2 };

    // Create an unordered_map to store the count of each number
    std::unordered_map<int, int> countMap;
    std::set<int> mySet;
    // Iterate through the array and update the counts in the hashmap
    for (int num : arr3) {
        countMap[num]++;

    }


    // Display the counts
    for (const auto& entry : countMap) {
        std::cout << "Number: " << entry.first << ", Occurence: " << entry.second << std::endl;
    }

    std::unordered_map<int, int> freqMap;
    for (const auto& entry : countMap) {
        freqMap[entry.second]++;
        if (freqMap[entry.second] > 1)
        {
            return false;
        }
    }
    return true;
    for (const auto& entry : freqMap) {
        std::cout << "Occurence: " << entry.first << ", count: " << entry.second << std::endl;
    }
    */

    
    /*
    //find duplicate for 0 to n-1 in which 1 to n-1 is present. Only one number is repeated.
    int arr[] = {2,5,4,1,3,4};
    int res = 0;
    for (int i = 0; i < 6; i++)
    {
        res = res ^ arr[i];
    }
    for (int i = 1; i < 6; i++)
    {
        res = res ^ i;
    }
    cout << "res: " << res << endl;

    */

    /*
    //print all multiple occurence
    vector<int>nums = {1,2,2,2,4,5,5};
    vector<int>res;
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++)
    {
        //res[arr[i]]++;
        //res[nums[i]]++;
        myMap[nums[i]]++;
    }
    for (const auto entry:myMap)
    {
        if (entry.second > 1)
        {
            res.push_back(entry.first);
            cout << "first: " << entry.first << " Sec:" << entry.second << endl;
        }

    }
    */

    /*
    //array intersection for unsorted
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = { 2,2, 3};
    unordered_map<int, int> myMap;
    vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
    {
        int element = nums1[i];
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums2[j] == element)
            {
                res.push_back(element);
                myMap[element];
                nums2[j] = -1;
                break;
            }
        }
    }
    for (const auto entry : myMap)
    {

            res.push_back(entry.first);
            cout << "first: " << entry.first << " Sec:" << entry.second << endl;

    }
    //for sorted array use two pointers for above problem

    */

    /*

    //two sum problem with brute force
    //check this solution with hash maps
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
            if ((nums[j] + ele) == target)
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    //return res;
    */

    /*
    //sort 0 1 2 or Dutch flag
    //75. Sort Colors
    vector<int> vec = { 1,0,2,2,1,0,0,1 };
    int low = 0;
    int high = vec.size() - 1;
    int mid = 0;

    while (mid <= high)
    {
        switch (vec[mid]) {
        case 0:
            swap(vec[low], vec[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(vec[mid], vec[high]);
            high--;
            break;
        }

    }
    printVec(vec);
    */


    /*
        //first and last occurence of target
        vector<int> nums = { 5,7,7,8,8,8,8,10 };
        int target = 8;

        vector<int> First = firstOcc(nums, target);
        vector<int> Last = lastOcc(nums, target);
        vector<int> Res;
        if (!First.empty()) {
            Res.push_back(First.back());
        }
        if (!Last.empty()) {
            Res.push_back(Last.back());
        }


        vector<int> Res;

        //Do Binary search Hard problems

    */
    /*
        //reverse an interger. Handle case where res*10 goes beyond INT_MAX range.
        //to fix that limit the multiplication by checking (res > INT_MAX/10) same for (res < INT_MIN/10)
        int num = 123;
        int res = 0;
        while (num!=0)
        {
            int remainder = num % 10;
            if (res > INT_MAX / 10 || res < INT_MIN / 10)
            {
                return 0;
            }
            res = res * 10 + remainder;
            num = num / 10;
        }
        cout << res << endl;
        */

    /*
    vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    //for duplicate elements like above use linear search
    int pIndex = findPivotGPT(nums);
    int start = 0;
    int end = nums.size() - 1;
    int target = 2;
    int foundIndex = 0;
    if (target >= nums[pIndex] && target <= nums[end])
        foundIndex = binarySearchInRotated(nums, pIndex, end, target);
    else
        foundIndex = binarySearchInRotated(nums, start, pIndex, target);
   
    cout << target << " found at: " << foundIndex << endl;
   
   */

    /*
    //solve all binary search problem with recurrsion
    vector<char> s = { 's','a','g','a','r'};
    int i = 0;
    int j = s.size()-1;
    solve(s, i, j);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    */
    
    /*
    //rotate array by using moduls logic. Use % for cyclic
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    rotate(nums, 2);
    printVec(nums);
    */
    
    // solve sieve of eratosthenes

    //gcd
    int a = 72;
    int b = 24;
    if (a == 0) return b;
    if (b == 0) return a;
    while (a!=b)
    {
        if (a > b) a = a - b;
        if (a < b) b = b - a;
    }
    cout << a;
    
    //hw for Basic Math for DSA
    //piegon hole
    //catalon number
    //inclusion exclusion principle
    //factorial of large using mod 10^9
    //GCD reference: https://www.codingninjas.com/blog/202... 
    //Modular Arithmetics Reference : https://codeforces.com/blog/entry/72527 


}
