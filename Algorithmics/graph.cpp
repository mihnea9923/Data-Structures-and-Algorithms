#include "graph.h"
void graph::dfs(int v)
{
	//s.push(v);
	cout << v << " ";
	visited[v] = true;
	for (auto it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if(visited[*it] == false)
		dfs(*it);
	}
	//s.pop();
}