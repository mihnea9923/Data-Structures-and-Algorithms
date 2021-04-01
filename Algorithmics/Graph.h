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

class Edge {
public:
	int source;
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
	void addUndirectedEdge(int source, int destination, int weight);
	void addDirectedEdge(int source, int destination, int weight);
	void dfs(int source);
	void bfs(int source);
	void topologicalSort();
	void dijkstra(int source);
	void bellmanFord(int source);
private:
	int vertices;
	list<Node>* adjList;
	vector<Edge> edges;
	void dfsUtil(int source, bool* visited);
	void bfsUtil(int source, bool* visited);
	void topologicalSortUtil(int current , bool* visited , stack<int>& order);
	bool* createVisitedVector();
	int minDistance(int* distance , bool* visited);
	void addEdge(int source , int destination , int weight);
	bool detectBellmanFordCycle(int* destination);
};

