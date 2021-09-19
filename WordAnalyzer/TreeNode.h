#pragma once
#include <string>
using namespace std;

class TreeNode {
	friend class WordAnalyzer;
private:
	string data;
	int count;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode();
	TreeNode(string);
};
