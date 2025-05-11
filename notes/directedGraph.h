#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class directedGraph
{
private:
	class vertex
	{
	public:
		string data;

		//adjacency list
		vector<vertex*> neighbors;

		vertex(string x)
		{
			data = x;
		}
	};

	//a container to hold the vertices
	unordered_map<string, vertex*> vertexMap;

public:

	void addVertex(string x)
	{
		vertexMap[x] = new vertex(x);
	}


	void addDirectedEdge(string x, string y)
	{
		vertex* xVert = vertexMap[x];
		vertex* yVert = vertexMap[y];

		xVert->neighbors.push_back(yVert);
	}

	void addBasicEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}


};