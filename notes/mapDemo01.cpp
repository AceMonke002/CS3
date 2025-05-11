#include <iostream>
#include <string>
#include <unordered_map> //hash table
#include <map>  //balanced binary search tree
using namespace std;

void showStats(unordered_map<string, double>& m)
{
	cout << "size: " <<  m.size() << endl;
	cout << "number buckets: " << m.bucket_count() << endl;
	cout << "load factor: " << m.load_factor() << endl;
	cout << "max load factor: " << m.max_load_factor() << endl;


	cout << endl;
}

int main()
{
	//Stores key-value pairs
	//key MUST be hashable
	//value can be anthing
	unordered_map<string, double> gpa;

	showStats(gpa);

	pair <string, double> p1;
	p1.first = "Jon";
	p1.second = 3.6;

	pair <string, double> p2;
	p2.first = "Eric";
	p2.second = .7;

	pair <string, double> p3;
	p3.first = "Josvaldo";
	p3.second = 1.3;
	
	pair <string, double> p4;
	p4.first = "Jade";
	p4.second = 4.0;

	//insert pairs into map
	//run time: w.c. O(n), a.c. O(1)
	gpa.insert(p1);
	gpa.insert(p2);
	gpa.insert(p3);
	gpa.insert(p4);
	//Can use bracket notation to insert
	gpa["Efren"] = 2.2;
	gpa["Corbin"] = 5;
	gpa["Eraan"] = 4.0;
	gpa["Andres"] = 4.1;
	gpa["Nathan"] = 2.2;

	//Can modify mappings
	swap(gpa["Josvaldo"], gpa["Corbin"]);


	showStats(gpa);

	//Can search up items by key
	//Find: w.c. O(n), a.c. O(1)
	cout << gpa.at("Eric") << endl;
	cout << gpa.at("Jade") << endl;
	cout << gpa["Jon"] << endl;
	cout << gpa["Efren"] << endl;

	//can iterate through all items
	for (auto x : gpa)
	{
		cout << x.first << " : " << x.second << " is at bucket: " << gpa.bucket(x.first) << endl;
	}


	return 0;
}