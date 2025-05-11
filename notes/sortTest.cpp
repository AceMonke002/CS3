
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

//Let n be the size of V, i.e. n = V.size()
//Run time: O(1) + #loops*O(1) = O(1)+n*O(1)=O(n)
void testDisplay1(vector<double> &V) //O(1)
{
	for (auto x : V) //#loops: n
	{
		cout << x << endl; //O(1)
	}
}

//Let n be the size of V, i.e. n = V.size()
//Run time: O(1) + n*O(1) = O(1) + O(n) = O(n)
void testDisplay(vector<double>& V) //O(1)
{
	for (int i=0; i<V.size(); i++) //#loops: n
	{
		cout << V[i] << endl; //like 3 = O(1)
	}
}

//Let n= end -start +1 , number of items in range
//runtime: O(1) + O(1) + O(n) + O(1) = O(n)
int findSmallest(vector<double> &V, int start, int end) //O(1)
{
	int smallest = start; //O(1);

	//n*O(1)=O(n)
	for (int i = start; i <= end; i++) //#loops: n
	{
		if (V[i] < V[smallest]) //O(1)
			smallest = i;
	}

	return smallest; //O(1)
}

//Let n = V.size()
//Run time: O(n^2)
void selectionSort(vector<double>& V)
{
	//n*( O(n) + O(1) ) = n*O(n)= O(n^2)
	for (int i = 0; i < V.size(); i++) //#loops: n
	{
		int small = findSmallest(V, i, V.size() - 1); //O(n)
		swap(V[i], V[small]); //O(1)
	}
}

//run time: O(n log n) + O(n log n)
//= O(n log n)
void heapSort(vector<double>& V)
{
	priority_queue<double> H; //a heap

	//step 1: insert items into a heap
	//#loops*CostPerLoop = n*O(log n) = O(n log n)
	for (int i = 0; i < V.size(); i++) //#loops: n
		H.push(V[i]);  //O(log n)

	//step 2: extract item from heap
	//n* (O(1)+O(log n))= n*O(log n) = O(n log n)
	for (int i = 0; i < V.size(); i++)//#loops: n
	{
		V[i] = H.top(); //O(1)
		H.pop();        //O(log n)
	}
}

int main()
{
	vector<double> nums;

	nums.push_back(58.7);
	nums.push_back(300);
	nums.push_back(3.14);
	nums.push_back(89);
	nums.push_back(130.8);
	nums.push_back(-18);
	nums.push_back(53);

	//Warmup 0:
	testDisplay(nums);
	cout << endl;

	//Warmup 1:
	cout << findSmallest(nums, 0, nums.size() - 1) << endl; // 5
	cout << findSmallest(nums, 0, 4) << endl; // 2
	cout << findSmallest(nums, 3, 4) << endl; // 3

	cout << endl;

	//Let's sort the list
	selectionSort(nums);
	testDisplay(nums);
	cout << endl;

	//Stress test:
	int huge = 1000000;
	vector<double> X;

	for (int i = 0; i < huge; i++)
		X.push_back(rand());

	auto start = chrono::high_resolution_clock::now();
	//selectionSort(X);
	heapSort(X);
	auto finish = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed = finish - start;
	cout << "Elapsed time: " << elapsed.count() << " seconds." << endl;

	//testDisplay(X);

	return 0;
}

/*
auto start = chrono::high_resolution_clock::now();
//code to time
auto finish = chrono::high_resolution_clock::now();

chrono::duration<double> elapsed = finish - start;
cout << "Elapsed time: " << elapsed.count() << " seconds." << endl;
*/