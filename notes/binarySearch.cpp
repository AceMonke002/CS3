
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Recursive binary search:
//Recurrence equation T(n) = T(n/2) + O(1) = O(log n)
int recBS(vector<double>& V, int start, int end, double key)
{
	if (end < start)//whoa, no items to search!
	{
		return -1;
	}
	else //recursive case:
	{
		int m = (start + end) / 2;

		if (key == V[m])
		{
			return m;
		}
		else if(key < V[m])
		{
			return recBS(V, start, m - 1, key);
		}
		else // key > V[m]
		{
			return recBS(V, m + 1, end, key);
		}
	}
}

//Let n = e-s+1
//Run time: O(log n)
int binarySearch(vector<double>& V, int start, int end, double key)
{
	int s = start;
	int e = end;

	while (s <= e)//#loops: at most log_2 n
	{
		//body runtime: O(1)
		int m = (s + e) / 2;
		
		if (key == V[m])
		{
			return m;
		}
		else if (key < V[m])
		{
			e = m - 1;
		}
		else // key > V[m]
		{
			s = m + 1;
		}
	}
	return -1;
}



int main()
{
	vector<double> A;

	A.push_back(2.1); //0
	A.push_back(4.8); //1
	A.push_back(14);  //2
	A.push_back(21.3); //3
	A.push_back(31); //4
	A.push_back(38); //5
	A.push_back(43.8); //6
	A.push_back(51); //7
	A.push_back(87); //8
	A.push_back(92); //9
	A.push_back(103.9); //10
	A.push_back(121);  //11
	A.push_back(143); //12
	A.push_back(157); //13
	A.push_back(253.2); //14
	A.push_back(412); //15

	//Quiz #1:

	/*
	//Implement a basic linear search
	cout << linearSearch(A, 0, A.size() - 1, 143) << endl;		//12
	cout << linearSearch(A, 5, 9, 21.3) << endl;				//-1 (number isn't in given range)
	cout << linearSearch(A, 0, A.size() - 1, 4.8) << endl;		//1
	cout << linearSearch(A, 0, A.size() - 1, 412) << endl;		//15
	cout << linearSearch(A, 0, A.size() - 1, 21.3) << endl;		//3
	*/

	//Implement a binary search
	cout << binarySearch(A, 0, A.size() - 1, 143) << endl;		//12
	cout << binarySearch(A, 5, 9, 21.3) << endl;				//-1 (number isn't in given range)
	cout << binarySearch(A, 0, A.size() - 1, 4.8) << endl;		//1
	cout << binarySearch(A, 0, A.size() - 1, 412) << endl;		//15
	cout << binarySearch(A, 0, A.size() - 1, 21.3) << endl;		//3
	
	return 0;
}