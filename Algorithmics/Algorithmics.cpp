#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<string.h>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "Graph.h"
using namespace std;

int main()
{
	/*Graph g(9);
	g.addUndirectedEdge(0, 1, 4);
	g.addUndirectedEdge(0, 7, 8);
	g.addUndirectedEdge(1, 7, 11);
	g.addUndirectedEdge(1, 2, 8);
	g.addUndirectedEdge(2, 8, 2);
	g.addUndirectedEdge(2, 5, 4);
	g.addUndirectedEdge(2, 3, 7);
	g.addUndirectedEdge(3, 4, 9);
	g.addUndirectedEdge(3, 5, 14);
	g.addUndirectedEdge(4, 5, 10);
	g.addUndirectedEdge(5, 6, 2);
	g.addUndirectedEdge(6, 8, 6);
	g.addUndirectedEdge(6, 7, 1);
	g.addUndirectedEdge(7, 8, 7);
	g.dijkstra(0);*/

	/*Graph g(6);
	g.addDirectedEdge(5, 2, 0);
	g.addDirectedEdge(5, 0, 0);
	g.addDirectedEdge(4, 0, 0);
	g.addDirectedEdge(4, 1, 0);
	g.addDirectedEdge(2, 3, 0);
	g.addDirectedEdge(3, 1, 0);
	g.topologicalSort();*/


	Graph g(5);
	g.addDirectedEdge(0, 1, -1);
	g.addDirectedEdge(0, 2, 4);
	g.addDirectedEdge(4, 3, -3);
	g.addDirectedEdge(1, 2, 3);
	g.addDirectedEdge(1, 3, 2);
	g.addDirectedEdge(1, 4, 2);
	g.addDirectedEdge(3, 2, 5);
	g.addDirectedEdge(3, 1, 1);
	g.bellmanFord(0);
	return 0;
}

