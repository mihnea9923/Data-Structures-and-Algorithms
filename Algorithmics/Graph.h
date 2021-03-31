#pragma once
#include "Libs.h"
#include <list>
#include <stack>
#include <queue>
class Node {
public:
	int destination;
	int weight;
};

class Graph
{
public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		adjList = new list<Node>[vertices];
	}
	void addEdge(int source, int destination, int weight);
	void dfs(int source);
	void bfs(int source);
	void topologicalSort();
	void dijkstra();
private:
	int vertices;
	list<Node>* adjList;
	void dfsUtil(int source, bool* visited);
	void bfsUtil(int source, bool* visited);
	bool* createVisitedVector();


};

