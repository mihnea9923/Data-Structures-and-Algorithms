#include "Graph.h"
void Graph::addUndirectedEdge(int source, int destination, int weight)
{
	Node newNode;
	newNode.destination = destination;
	newNode.weight = weight;
	adjList[source].push_back(newNode);
	newNode.destination = source;
	adjList[destination].push_back(newNode);
	addEdge(source, destination, weight);
}

void Graph::addDirectedEdge(int source, int destination, int weight)
{
	Node newNode;
	newNode.destination = destination;
	newNode.weight = weight;
	adjList[source].push_back(newNode);
	addEdge(source, destination, weight);
}

void Graph::addEdge(int source, int destination, int weight)
{
	Edge edge;
	edge.source = source;
	edge.destination = destination;
	edge.weight = weight;
	edges.push_back(edge);
}

bool* Graph::createVisitedVector()
{
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visited[i] = false;
	return visited;

}


void Graph::dfs(int source)
{
	bool* visited = createVisitedVector();
	dfsUtil(source, visited);
	delete[]visited;
}

void Graph::dfsUtil(int source, bool* visited)
{
	if (visited[source])
		return;
	visited[source] = true;
	cout << source << " ";
	for (auto it = adjList[source].begin(); it != adjList[source].end(); it++)
		dfsUtil(it->destination, visited);
}


void Graph::bfs(int source)
{
	bool* visited = createVisitedVector();
	bfsUtil(source, visited);
	delete[]visited;
}

void Graph::bfsUtil(int source, bool* visited)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;
	while (q.empty() == false)
	{
		int front = q.front();
		cout << front << " ";
		q.pop();
		for (list<Node>::iterator it = adjList[front].begin(); it != adjList[front].end(); it++)
		{
			if (visited[it->destination] == false)
			{
				q.push(it->destination);
				visited[it->destination] = true;
			}
		}
	}
}


void Graph::topologicalSort()
{
	bool* visited = createVisitedVector();
	stack<int> order;
	for (int i = 0; i < vertices; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, order);
	while (order.empty() == false)
	{
		cout << order.top() << " ";
		order.pop();
	}
	delete[]visited;
}

void Graph::topologicalSortUtil(int current, bool* visited, stack<int>& order)
{
	if (visited[current])
		return;
	visited[current] = true;
	for (list<Node>::iterator it = adjList[current].begin(); it != adjList[current].end(); it++)
		topologicalSortUtil(it->destination, visited, order);
	order.push(current);
}


int Graph::minDistance(int* distances, bool* visited)
{
	int minIndex = 0, minValue = INT_MAX;
	for (int i = 0; i < vertices; i++)
		if (distances[i] < minValue && visited[i] == false)
		{
			minValue = distances[i];
			minIndex = i;
		}
	return minIndex;
}


void Graph::dijkstra(int source)
{
	bool* visited = createVisitedVector();
	int* distances = new int[vertices];
	for (int i = 0; i < vertices; i++)
		distances[i] = INT_MAX;
	distances[source] = 0;
	for (int i = 0; i < vertices - 1; i++)
	{
		int currentMin = minDistance(distances, visited);
		for (list<Node>::iterator it = adjList[currentMin].begin(); it != adjList[currentMin].end(); it++)
		{
			if (visited[it->destination] == false)
				distances[it->destination] = min(distances[it->destination], distances[currentMin] + it->weight);
		}
		visited[currentMin] = true;
	}
	for (int i = 0; i < vertices; i++)
		if (i != source)
			cout << "Vertex " << i << " distance " << distances[i] << endl;
	delete[]visited;
	delete[]distances;
}

void Graph::bellmanFord(int source)
{
	int* distances = new int[vertices];
	for (int i = 0; i < vertices; i++)
		distances[i] = INT_MAX;
	distances[source] = 0;
	for (int i = 0; i < vertices - 1; i++)
	{
		for (auto it : edges)
		{
			int source = it.source;
			int destination = it.destination;
			int weight = it.weight;
			if (distances[source] + weight < distances[destination])
				distances[destination] = distances[source] + weight;
		}
	}
	if (detectBellmanFordCycle(distances))
	{
		cout << "The graph contains negative weight cycle\n";
		return;
	}
	for (int i = 0; i < vertices; i++)
		cout << " destination" << i << " weight: " << distances[i] << endl;

	delete[] distances;
}

bool Graph::detectBellmanFordCycle(int* distances)
{
	for (auto it : edges)
	{
		int source = it.source;
		int destination = it.destination;
		int weight = it.weight;
		if (distances[source] + weight < distances[destination])
			return true;
	}
	return false;
}