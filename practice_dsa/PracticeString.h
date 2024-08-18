#pragma once
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;

class PracticeString
{
public:
	static bool checkPalindrome(string& inputString);
	static string firstPalindrome(vector<string>& words);
	static char lowerToUppar(char& input);
	static string upparToLower(string& input);
	static std::string removeNonAlphanumericAndToLower(std::string& input);
	static char upparToLower(char& input);
	static int lengthOfLastWord(string& s);
	static string reverseString(string inputStr);
	static string reverseStringTillPostion(string inputStr, int k);
	static string trimString(string s);
	static string reverseWords(string s);
	static string reversePrefix(string inputStr, char ch);
	static bool isValid(char s);
	static string reverseOnlyLetters(string s);
	static string removeOccurrences(string s, string part);
	static int maxOccurenceOfChar(string s);
	static bool checkArrayEqual(int* arr1, int* arr2);
	static bool checkInclusion(string s1, string s2);
	static string removeDuplicates(string s);
	static string longestCommonPrefix(const std::vector<std::string>& strs);

};


