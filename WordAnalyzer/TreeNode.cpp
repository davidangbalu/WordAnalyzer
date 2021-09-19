#include "TreeNode.h"
#include <string>
using namespace std;

TreeNode::TreeNode() {
	data = "";
	count = 0;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(string word) {
	data = word;
	count = 1;
	left = NULL;
	right = NULL;
}