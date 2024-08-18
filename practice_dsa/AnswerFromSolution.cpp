#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;

struct ListNode1 {
    int val;
    ListNode1* next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1* next) : val(x), next(next) {}
};

long long maximumSubarraySumSol(vector<int>& nums, int k) {
    int i = 0, j = 0, n = nums.size();
    long long ans = 0, sum = 0;
    unordered_map<int, int> m;

    while (j < n) {
        m[nums[j]]++;
        sum += nums[j];

        if ((j - i + 1) < k) {
            j++;
        }
        else {
            // if size == k means all elements are unique
            if (m.size() == k) {
                ans = max(ans, sum);
            }

            sum -= nums[i];
            m[nums[i]]--;

            // if ith element frequency is 0 then erase that element otherwise it will be counted in m.size()
            if (m[nums[i]] == 0) {
                m.erase(nums[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}

double findMaxAverageSol(vector<int>& nums, int k) {
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    int max_sum = sum;
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k];
        max_sum = max(sum, max_sum);

    }
    return (double)max_sum / k;

}

//ListNode1* addTwoNumbersGPT(ListNode1* l1, ListNode1* l2) {
//    ListNode1* dummyHead = new ListNode1(0); // Dummy head to simplify adding nodes
//    ListNode1* ListNode1 = dummyHead;
//    int carry = 0;
//    ListNode1* current = NULL;
//    ListNode1* head = NULL;
//    while (l1 != NULL || l2 != NULL || carry != 0) {
//        int sum = carry;
//        if (l1 != NULL) {
//            sum += l1->val;
//            l1 = l1->next;
//        }
//        if (l2 != NULL) {
//            sum += l2->val;
//            l2 = l2->next;
//        }
//        carry = sum / 10; // Calculate carry for the next iteration
//        current->next = new ListNode1(sum % 10); // Create a new node with the remainder
//        current = current->next; // Move to the next node
//    }
//
//    ListNode1* head = dummyHead->next; // The real head of the result list
//    delete dummyHead; // Delete the dummy head node
//    return head; // Return the head of the result list
//}



class trieNode
{
public:

	char data;
	trieNode* children[26];
	bool isTerminal;

	//constructor
	trieNode(char ch)
	{
		this->data = ch;
		for (int i = 0; i < 26; i++)
		{
			this->children[i] = NULL;
		}
		isTerminal = false;
	}

private:

};




class trie
{
public:

	trieNode* root;
	trie()
	{
		root = new trieNode('\0');
	}
    void insertUtil(trieNode* root, string word) {
        // Base case: if the word to insert is empty
        if (word.length() == 0) {
            // Mark the current node as the end of a word
            root->isTerminal = true;
            return;
        }

        // Calculate the index for the current character
        int index = word[0] - 'a';
        trieNode* newChild;

        // Check if the child node corresponding to the current character exists
        if (root->children[index] != NULL) {
            // Child is present, use this child for further insertion
            newChild = root->children[index];
        }
        else {
            // Child is absent, create a new child node
            newChild = new trieNode(word[0]); // Assuming trieNode has a default constructor
            // Initialize the new child node if necessary (e.g., set isTerminal to false)
            // newChild->isTerminal = false;
            // Add the newly created child to the current node
            root->children[index] = newChild;
        }

        // Recursively insert the remaining substring into the trie
        insertUtil(newChild, word.substr(1));
    }


	void insert(string word) {
		return insertUtil(root, word);
	}

    bool searchUtil(trieNode* root, string word) {
        // Base case: if the word to search is empty
        if (word.length() == 0) {
            // Check if the current node is marked as the end of a word
            if (root->isTerminal) {
                return true; // Word found
            }
            else {
                return false; // Word not found
            }
        }

        // Calculate the index for the current character
        int index = word[0] - 'a';
        trieNode* newChild;

        // Check if the child node corresponding to the current character exists
        if (root->children[index] != NULL) {
            // Child is present, continue the search with the next character
            newChild = root->children[index];
        }
        else {
            // Child is absent, the word does not exist in the trie
            return false;
        }

        // Recursively search for the remaining substring in the trie
        return searchUtil(newChild, word.substr(1)); // Fixed: added return statement
    }

	bool searchWord(string word) {
		return searchUtil(root, word);
	}

private:

};


