// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
#define INF 0x7fffffff

typedef pair<int, int> intPair;

class Graph
{
	int V;

	list<pair<int, int>> *adj;

public:
	Graph(int V); // Constructor

	void addEdge(int u, int v, int w);

	void shortestPath(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<intPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
	priority_queue<intPair, vector<intPair>, greater<intPair>> pq;

	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize its distance as 0
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		list<pair<int, int>>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	// Print shortest distances
	printf("Vertex \t\tDistance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t\t %d\n", i, dist[i]);
}

int main()
{
	time_t start, end;
	int V = 9;
	Graph g(V);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	start = clock();
	g.shortestPath(7);
	end = clock();

	printf("\nTime taken: %.9fs\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}