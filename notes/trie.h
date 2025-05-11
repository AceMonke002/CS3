#pragma once
#include <iostream>
#include <string>
using namespace std;

class trie
{
private:
	class node
	{
	public:
		bool marked;
		node* children[256];

		node()
		{
			marked = false;
			for (int i = 0; i < 256; i++)
				children[i] = nullptr;
		}
	};

	node* root;

	//Print all strings in trie rooted at p
	//with prefix pref in front of it.
	void recDisplay(node* p, string pref)
	{
		if(p==nullptr)
		{ }
		else
		{
			if (p->marked)
				cout << pref << endl;

			for (int i = 0; i < 256; i++)
				recDisplay(p->children[i], pref + (char)i);
		}
	}

public:
	trie()
	{
		root = new node;
	}

	//O(l) run time, where l= s.length()
	void insert(string s)
	{
		node* arrow = root;

		for (int i=0; i<s.length(); i++)
		{
			if (arrow->children[s[i]] == nullptr)
				arrow->children[s[i]] = new node;

			arrow = arrow->children[s[i]];
		}

		arrow->marked = true;
	}

	void display()
	{
		recDisplay(root, "");
	}
};