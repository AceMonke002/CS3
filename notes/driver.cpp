
#include <iostream>
#include <string>
#include "bst.h"
using namespace std;

int main()
{
	binarySearchTree T;

	T.insert(54);
	T.insert(27);
	T.insert(83);
	T.insert(15);
	T.insert(21);
	T.insert(99);
	T.insert(53);
	T.insert(38);

	T.display();

	return 0;
}