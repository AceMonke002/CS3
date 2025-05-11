#pragma once
#include<iostream>
using namespace std;

class binarySearchTree
{
private:
	class node
	{
	public:
		double data;
		node* left;
		node* right;

		node(double x)
		{
			data = x;
			left = nullptr;
			right = nullptr;
		}
	};

	node* root;

	//insert x into the tree rooted at node p.
	void recInsert(node* &p, double x)
	{
		if (p == nullptr)
			p = new node(x);
		else
		{
			if (x < p->data)
				recInsert(p->left, x);
			else
				recInsert(p->right, x);
		}
	}

	//print items in tree rooted at node p
	//do it in an inorder traversal
	//Run time: O(n)
	void inOrderTraversal(node* p)
	{
		if(p==nullptr)
		{
			//don't print anything,
			//no nodes to print.
			//saving tons of time becasu
			//easy base case.
		}
		else
		{
			inOrderTraversal(p->left);
			cout << p->data << endl;
			inOrderTraversal(p->right);
		}
	}

public:
	binarySearchTree()
	{
		root = nullptr;
	}

	void insert(double x)
	{
		recInsert(root, x);
	}

	void display()
	{
		inOrderTraversal(root);
	}
};