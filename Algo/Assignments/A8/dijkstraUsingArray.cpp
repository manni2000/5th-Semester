#include <bits/stdc++.h>
#include <limits.h>
#include <time.h>

using namespace std;

#define V 9
#define __INT_MAX__ 0x7fffffff

int minDistance(int dist[], bool present[])
{
	int min = INT_MAX, min_index = INT_MAX;
	for (int i = 0; i < V; i++)
	{
		if (present[i] == false and min >= dist[i])
		{
			min_index = i;
			min = dist[i];
		}
	}
	return min_index;
}

void printShortestDistArray(int dist[])
{
	cout << "Node\t Distance from source\n";
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t\t\t" << dist[i] << "\n";
	}
}

void dijkstra(int graph[V][V], int source)
{

	int dist[V];	 // shortest distance of node from start node
	bool present[V]; // know if the node is present in the shortest path tree
	for (int i = 0; i < V; i++)
	{
		dist[i] = __INT_MAX__;
		present[i] = false;
	}

	dist[source] = 0;

	// cout <<"Check4\n";

	for (int count = 0; count < V - 1; count++)
	{

		int u = minDistance(dist, present);

		present[u] = true;

		for (int i = 0; i < V; i++)
		{

			if (!present[i] and graph[u][i] and dist[u] != INT_MAX and (dist[u] + graph[u][i]) < dist[i])
			{
				dist[i] = dist[u] + graph[u][i];
			}
		}
	}
	printShortestDistArray(dist);
}

int main()
{

	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
					   {4, 0, 8, 0, 0, 0, 0, 11, 0},
					   {0, 8, 0, 7, 0, 4, 0, 0, 2},
					   {0, 0, 7, 0, 9, 14, 0, 0, 0},
					   {0, 0, 0, 9, 0, 10, 0, 0, 0},
					   {0, 0, 4, 14, 10, 0, 2, 0, 0},
					   {0, 0, 0, 0, 0, 2, 0, 1, 6},
					   {8, 11, 0, 0, 0, 0, 1, 0, 7},
					   {0, 0, 2, 0, 0, 0, 6, 7, 0}};
	/*for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			int r = rand() % 20;
			int result = (r & 1) ? r : 0;
			graph[i][j] = result;
		}
	}*/
	time_t start = clock();
	dijkstra(graph, 7);
	time_t end = clock();
	printf("\nTime taken: %.9fs\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}