#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<regex>
#include "TreeNode.h"
#include "WordAnalyzer.h"

using namespace std;

int main()
{
	WordAnalyzer myWordAnalyzer = WordAnalyzer();

	string word[] = { "a", "an", "and", "as", "at",
			"be", "an", "and", "are", "a" , "as", "at", "be",
	"by", "for", "from", "has", "he", "in", "is","it", "its", "of",
	"on", "that", "the", "to", "she", "was", "where", "will", "with" };

	for (string i : word) {
		myWordAnalyzer.addStopgapWord(i);
	}

	ifstream readIn;
	readIn.open("text.txt");

	while (!readIn.eof()) {
		string word;
		readIn >> word;
		myWordAnalyzer.addWord(word);
	}

	readIn.close();
	myWordAnalyzer.displaydata();
	cout << "most common word is: " << myWordAnalyzer.getMostCommonWord();

	return 0;
}