#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;

class WordAnalyzer {
	friend class TreeNode;
private:
	TreeNode* root;
	void insert(string data, TreeNode*& root);
	void inOrder(TreeNode* root);
public:
	string maxWord;
	int maxCount;
	WordAnalyzer();
	vector<string> stopgapword;
	void addWord(string word);
	bool isValidWord(string);
	void displaydata();
	void addStopgapWord(string);
	bool isStopgapWord(string);
	void mostCommonWord(TreeNode*, string, int);
	string getMostCommonWord();
};