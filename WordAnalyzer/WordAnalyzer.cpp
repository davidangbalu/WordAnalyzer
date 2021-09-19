#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<regex>
#include "TreeNode.h"
#include "WordAnalyzer.h"

using namespace std;

WordAnalyzer::WordAnalyzer() {
	root = NULL;
}

void WordAnalyzer::insert(string word, TreeNode*& root) {

	/***************************************************************************************

	*    Usage: Used
	*    Title: C++ convert word in type string variable to lowercase [duplicate]
	*    Author: Soren
	*    Date: 26/04/2014
	*    Code version: 1.0
	*    Availability: https://stackoverflow.com/questions/23313498/c-convert-word-in-type-string-variable-to-lowercase
	*
	***************************************************************************************/

	transform(word.begin(), word.end(), word.begin(), ::tolower);

	/***************************************************************************************

	*    Usage: Used
	*    Title: Removing punctuations from a given string
	*    Author: 29AjayKumar
	*    Date: 05/12/2018
	*    Code version: 1.0
	*    Availability: https://www.geeksforgeeks.org/removing-punctuations-given-string/
	*
	***************************************************************************************/

	for (int i = 0, len = word.size(); i < len; i++) {

		if (ispunct(word[i])) {
			word.erase(i--, 1);
			len = word.size();
		}
	}

	if (isValidWord(word)) {
		if (isStopgapWord(word)) {
			if (root == NULL) {
				root = new TreeNode(word);
			}
			else if (root->data == word) {
				root->count++;
			}
			else {
				if (word >= root->data) {
					insert(word, root->right);
				}
				if (word <= root->data) {
					insert(word, root->left);
				}
			}
		}
	}
}

void WordAnalyzer::addWord(string word) {
	insert(word, root);
}

void WordAnalyzer::inOrder(TreeNode* root) {

	if (root != NULL) {

		if (root->left != NULL) {
			inOrder(root->left);
		}
		cout << root->data << " ";
		cout << root->count << endl;
		if (root->right != NULL) {
			inOrder(root->right);
		}
	}
	else {
		cout << "There are no words in here.";
	}

}

void WordAnalyzer::displaydata() {
	inOrder(root);
}

bool WordAnalyzer::isValidWord(string word) {

	for (int i = 0; i < word.size(); i++)
	{
		/***************************************************************************************

		*    Usage: Used
		*    Title: Writing a function to check if a word is valid
		*    Author: Armin Montigny
		*    Date: 13/08/2020
		*    Code version: 1.0
		*    Availability: https://stackoverflow.com/questions/63387740/writing-a-function-to-check-if-a-word-is-valid/63392695#63392695
		*
		***************************************************************************************/
		if (std::regex_match(word, std::regex("[a-z]+"))) {
			return true;
		}
	}

	return false;

}

void WordAnalyzer::addStopgapWord(string word) {
	stopgapword.push_back(word);
}

bool WordAnalyzer::isStopgapWord(string word) {
	for (int i = 0; i < stopgapword.size(); i++) {
		if (word == stopgapword[i]) {
			return false;
		}
	}
	return true;
}

void WordAnalyzer::mostCommonWord(TreeNode* root, string word, int count) {
	maxWord = "";
	maxCount = 1;
	if (root != NULL) {
		mostCommonWord(root->left, word, count);
		if (word != root->data) {
			word = root->data;
			count = 1;
		}
		else {
			count++;
		}
		if (count > maxCount) {
			maxWord = word;
			maxCount = count;
		}
		mostCommonWord(root->right, word, count);
	}
			
}

string WordAnalyzer::getMostCommonWord() {
	if (root != NULL) {
		maxWord = root->data;
		maxCount = 1;
		string word = root->data;
		int count = 1;
		mostCommonWord(root, word, count);
		return maxWord;
	}
}

