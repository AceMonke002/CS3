#pragma once
#include<iostream>
using namespace std;

class AVLtree
{
private:
	class node
	{
	public:
		double data;
		node* left;
		node* right;

		int height;

		node(double x)
		{
			data = x;
			left = nullptr;
			right = nullptr;
			height = 0;
		}
	};

	node* root;

	int height(node* p)
	{
		if (p == nullptr)
			return -1;
		else
			return p->height;
	}

	void updateHeight(node* p)
	{
		p->height = 1 + max(height(p->left), height(p->right));
	}

	void leftRotate(node*& p)
	{
		node* A = p;
		node* B = p->right;
		node* bl = B->left;

		p = B;
		B->left = A;
		A->right = bl;

		updateHeight(A);
		updateHeight(B);
	}

	void rightRotate(node*& p)
	{
		node* A = p;
		node* B = p->left;
		node* br = B->right;

		p = B;
		B->right = A;
		A->left = br;

		updateHeight(A);
		updateHeight(B);
	}

	void rightLeft(node*& p)
	{
		rightRotate(p->right);
		leftRotate(p);
	}

	void leftRight(node*& p)
	{
		leftRotate(p->left);
		rightRotate(p);
	}

	void fixBalance(node*& p)
	{
		if (height(p->right) - height(p->left) >= 2)
		{
			if (height(p->right->right) > height(p->right->left))
				leftRotate(p);
			else
				rightLeft(p);
		}
		else if (height(p->left) - height(p->right) >= 2)
		{
			if (height(p->left->left) > height(p->left->right))
				rightRotate(p);
			else
				leftRight(p);
		}
		else
		{
			//We find this node is not guilty of
			//SUSness.  Do no rotations.
		}
	}

	//insert x into the tree rooted at node p.
	void recInsert(node*& p, double x)
	{
		if (p == nullptr)
			p = new node(x);
		else
		{
			if (x < p->data)
				recInsert(p->left, x);
			else
				recInsert(p->right, x);

			//p's height is SUS
			updateHeight(p);

			//p's balance is SUS
			fixBalance(p);
		}
	}

	//print items in tree rooted at node p
	//do it in an inorder traversal
	//Run time: O(n)
	void inOrderTraversal(node* p)
	{
		if (p == nullptr)
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
	AVLtree()
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

	int height()
	{
		return height(root);
	}
};