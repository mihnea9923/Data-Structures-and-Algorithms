#include "Graph.h"
void Graph::addEdge(int source, int destination, int weight)
{
	Node newNode;
	newNode.destination = destination;
	newNode.weight = weight;
	adjList[source].push_back(newNode);
	newNode.destination = source;
	adjList[destination].push_back(newNode);
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
	delete(visited);
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
	delete(visited);
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