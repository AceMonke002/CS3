
#include <iostream>
#include <string>
#include <fstream>
#include "trie.h"
using namespace std;

int main()
{
	trie T;
	ifstream infile("words2.txt");

	string word;
	while (infile >> word)
	{
		int freq;
		infile >> freq;

		T.insert(word);
	}

	T.display();
	/*
	T.insert("bartholemule");
	T.insert("wAwa");
	T.insert("defen?itration");
	T.insert("deforest!ation");
	T.insert("bart");
	T.insert("barter");
	*/


	return 0;
}