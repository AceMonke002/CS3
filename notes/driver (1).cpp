
#include <iostream>
#include <string>
#include "bst.h"
#include "avl.h"
using namespace std;

int main()
{
	//binarySearchTree T;
	AVLtree T;

	T.insert(7);
	T.insert(12);
	T.insert(23);
	T.insert(4);
	T.insert(36);
	T.insert(2);
	T.insert(19);
	T.insert(10);
	T.insert(95);
	T.insert(65);
	T.insert(40);

	int big = 1000;
	for (int i = 0; i < big; i++)
		T.insert(i);//T.insert(rand());

	cout << "height is: " << T.height() << endl;
	cout << endl;
	//T.display();


	return 0;
}