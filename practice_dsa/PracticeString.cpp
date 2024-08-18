#pragma once
#include "PracticeString.h"
#include<string>
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;

bool PracticeString::checkPalindrome(string& inputString)
{
	int start = 0;
	int end = inputString.length() - 1;

	while (start <= end)
	{
		if (inputString[start] == inputString[end]) {
			start++;
			end--;
		}
		else
		{
			//cout << "Not a palindrome" << endl;
			return false;
		}
	}
	return true;
}

string PracticeString::firstPalindrome(vector<string>& words) {


	for (int i = 0; i < words.size(); i++)
	{
		string inputString = words[i];
		if (PracticeString::checkPalindrome(inputString))
		{
			return words[i];
		}
	}
	return "";
}

char PracticeString::lowerToUppar(char& input)
{
	//if input is already uppar case
	if (input >= 'A' && input <= 'Z')
	{
		return input;
	}
	else //input is lower case
	{
		//calculare the difference between input and 'a' character and add that difference from upparcase 'A'
		return input - 'a' + 'A';
	}
}

char PracticeString::upparToLower(char& input)
{
	//if input is already lower case
	if (input >= 'a' && input <= 'z')
	{
		return input;
	}
	else //input is uppar case
	{
		//calculare the difference between input and 'A' character and add that difference from lowercase 'a'
		return input - 'A' + 'a';
	}
}
string PracticeString::upparToLower(string & input)
{
	// Iterate over each character in the input string
	for (char& c : input) {
		// If the character is uppercase, convert it to lowercase
		if (c >= 'A' && c <= 'Z') {
			c = std::tolower(static_cast<unsigned char>(c));
		}
	}
	// Return the modified string
	return input;
}

std::string PracticeString::removeNonAlphanumericAndToLower(std::string& input) {
	std::string result;
	// Iterate over each character in the input string
	for (char c : input) {
		// Check if the character is alphanumeric (i.e., a letter or digit)
		if (std::isalnum(static_cast<unsigned char>(c))) {
			// Convert the character to lowercase and add it to the result string
			result += std::tolower(static_cast<unsigned char>(c));
		}
	}
	// Return the modified string
	return result;
}



int PracticeString::lengthOfLastWord(string& s) {

	int count = 0;
	for (int j = s.length() - 1; j >= 0; j--)
	{
		if ((s[j] == ' ') && count == 0) {
			continue;
		}
		else if ((s[j] == ' ') && count != 0)
		{
			return count;
		}
		else
		{
			count++;
		}

	}
	return count;
}

string PracticeString::reverseString(string inputStr) {


	int start = 0;
	int end = inputStr.length() - 1;
	while (start <= end)
	{
		swap(inputStr[start++], inputStr[end--]);
	}
	return inputStr;
}

string PracticeString::reverseStringTillPostion(string inputStr, int k) {

	int count = 0;
	int start = 0;
	int end = k;
	while (start <= end)
	{
		swap(inputStr[start++], inputStr[end--]);

	}
	return inputStr;
}

//IMP trimming string is not so straight forward so please take a look at this once again
string PracticeString::trimString(string s)
{
	string result = "";
	int validSpaceCount = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && (i == 0 || i == s.length() - 1))
		{
			validSpaceCount++;
			continue;
		}
		if (s[i] == ' ' && validSpaceCount < 1) {
			validSpaceCount++;
			result.push_back(s[i]);
		}
		if (s[i] != ' ')
		{
			validSpaceCount = 0;
			result.push_back(s[i]);
		}
	}
	int start = 0;
	int end = result.length() - 1;
	while (start <= end && result[start] == ' ')
	{
		start++;
	}
	while (start <= end && result[end] == ' ')
	{
		end--;
	}
	string finalresult = result.substr(start, end - start + 1);
	return finalresult;

}

string PracticeString::reverseWords(string s) {
	string trimmedStr = trimString(s); //trimming the white spaces
	cout << "Trimmed: " << trimmedStr << endl;
	string result = "";
	string finalResult = "";
	//for (int i = 0; i < s.length(); i++)
	//{
	//	
	//	if (trimmedStr[i] == ' ')
	//	{
	//		cout << "result: " << result << endl;
	//		string temp = reverseString(result);
	//		cout << "reverse: " << temp << endl;
	//		finalResult.append(temp);
	//		//finalResult.push_back(' ');
	//	}
	//	else
	//	{
	//		result.push_back(s[i]);
	//	}
	//	
	//}
	//cout << "Final: " << finalResult << endl;

	//if we see white space then we push that as word in a vector, else we keep pushing the letters to form a word
	vector<string> resultVec;
	for (int i = 0; i <= trimmedStr.length(); i++)
	{
		if (trimmedStr[i] == ' ' or i >= trimmedStr.length())
		{
			resultVec.push_back(result);
			//resultVec.push_back(" ");
			result.clear();
		}
		else
		{
			result.push_back(trimmedStr[i]);
		}

	}

	//result vector contains all the words
	//reverse the vector and handle last space condition for space
	//return the string by appending values of vector
	for (int i = resultVec.size() - 1; i >= 0; --i) {
		//std::cout << resultVec[i] << " ";
		finalResult.append(resultVec[i]);
		if (i == 0)
		{
			finalResult.append("");
			break;
		}
		finalResult.append(" ");

	}
	//cout << finalResult;
	return finalResult;
}

string PracticeString::reversePrefix(string inputStr, char ch) {

	int count = 0;
	int start = 0;
	int end = inputStr.length() - 1;
	while (start <= end)
	{
		if (inputStr[start] == ch)
		{

			break;
		}
		count++;
		start++;
		//swap(inputStr[start++], inputStr[end--]);

	}
	start = 0;
	end = count;
	while (start <= end)
	{
		swap(inputStr[start++], inputStr[end--]);
	}
	return inputStr;
}

bool PracticeString::isValid(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
		return true;
	}
	else
		return false;
}

string PracticeString::reverseOnlyLetters(string s) {
	int start = 0;
	int end = s.length() - 1;

	while (start <= end)
	{
		if (isValid(s[start]) && isValid(s[end]))
		{
			swap(s[start++], s[end--]);
		}
		else if (!isValid(s[start]))
		{
			start++;
		}
		else if (!isValid(s[end]))
		{
			end--;
		}
	}
	return s;
}

//read more on in-build function from internet
string PracticeString::removeOccurrences(string s, string part) {

	while (s.length() != 0 && s.find(part) < s.length())
	{
		s.erase(s.find(part), part.length());
	}
	return s;
}

int PracticeString::maxOccurenceOfChar(string s)
{
	int countArray[26] = { 0 };
	int start = 0;
	int end = s.length() - 1;

	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		countArray[index]++;
	}
	int maxCount = 0;
	char ch;
	for (int i = 0; i < 26; i++)
	{
		if (countArray[i] > maxCount) {
			//cout << countArray[i] << " ";
			maxCount = countArray[i];
			ch = 'a' + i; //index i represents char from 0 to 26. So just add this i from 'a' to get char
		}
	}
	cout << ch << " ";
	return maxCount;
}

bool PracticeString::checkArrayEqual(int* arr1, int* arr2)
{
	for (int i = 0; i < 26; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}

//567. Permutation in String Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
bool PracticeString::checkInclusion(string s1, string s2) {
	int countS1[26] = { 0 };
	int countS2[26] = { 0 };
	//count occurences of s1 string
	for (int i = 0; i < s1.length(); i++)
	{
		int index = s1[i] - 'a';
		countS1[index]++;
	}
	int windowSize = s1.length();
	int i = 0;
	//Check for first window
	while (i < windowSize && i < s2.length())
	{
		int index = s2[i] - 'a';
		countS2[index]++;
		i++;
	}
	//check if counts are equal
	if (checkArrayEqual(countS1, countS2))
	{
		//cout << "Array equal" << endl;
		return true;
	}
	//check for remaining s2 string
	//now at this point i will be at end of window. So we move windows forward by decrementing (i-windowSize) element and increasing count for next element

	while (i < s2.length())
	{
		//increase count for next element
		int newIndex = s2[i] - 'a';
		countS2[newIndex]++;

		//decrement count of older index which is out of window
		//old index will be i-windowsize

		char oldChar = s2[i - windowSize];
		int oldIndex = oldChar - 'a';
		countS2[oldIndex]--;
		if (checkArrayEqual(countS1, countS2))
		{
			//cout << "Array equal" << endl;
			return true;
		}
		i++;
	}

	return false;
}

//use greedy method to remove. use stack/vector and check top everytime we want to add new element
string PracticeString::removeDuplicates(string s) {
	vector<char> vec;
	for (int i = 0; i < s.length(); i++)
	{
		if (vec.empty())
		{
			vec.push_back(s[i]);
		}
		else if (vec.back() != s[i])
		{
			vec.push_back(s[i]);
		}
		else
		{
			vec.pop_back();
		}
	}
	string result(vec.begin(), vec.end());
	return result;
}


std::string PracticeString::longestCommonPrefix(const std::vector<std::string>& strs) {
	if (strs.empty()) return ""; // Check for an empty array of strings

	std::string prefix = strs[0]; // Start with the first string as the prefix

	for (int i = 1; i < strs.size(); ++i) { // Iterate through the strings
		int j = 0;
		for (; j < prefix.length() && j < strs[i].length(); ++j) {
			if (prefix[j] != strs[i][j]) {
				break; // Stop at the first mismatch
			}
		}
		prefix = prefix.substr(0, j); // Update the prefix
		if (prefix.empty()) return ""; // No common prefix
	}

	return prefix; // Return the longest common prefix

	//std::vector<std::string> strs = { "flower", "flow", "flight" };
	//std::cout << "Longest common prefix: " << longestCommonPrefix(strs) << std::endl;
}


