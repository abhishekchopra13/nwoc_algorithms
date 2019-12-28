// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>

using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm. The function
// also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	// Step 1: Initialize distances from src to all other vertices
	// as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times. A simple shortest
	// path from src to any other vertex can have at-most |V| - 1
	// edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles. The above step
	// guarantees shortest distances if graph doesn't contain
	// negative weight cycle. If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; // If negative cycle is detected, simply return
		}
	}

	printArr(dist, V);

	return;
}

// Driver program to test above functions
int main()
{
	int V ; // Number of vertices in graph
	int E ; // Number of edges in graph
	int s,d,w;
	cout << "Enter the number of vertices and edges.\n";
	cin >> V >> E;

	struct Graph* graph = createGraph(V, E);

	for(int i=0;i<E;i++)
    {
        cout << "Enter the source vertex, destination vertex and the edge weight.\n";
        cin >> s >> d >> w;
        graph->edge[i].src = s;
        graph->edge[i].dest = d;
        graph->edge[i].weight = w;
    }

	BellmanFord(graph, 0);

	return 0;
}

/*
SAMPLE INPUT :
Enter the number of vertices and edges.
5 8
Enter the source vertex, destination vertex and the edge weight.
0 1 -1
Enter the source vertex, destination vertex and the edge weight.
0 2 4
Enter the source vertex, destination vertex and the edge weight.
1 2 3
Enter the source vertex, destination vertex and the edge weight.
1 3 2
Enter the source vertex, destination vertex and the edge weight.
1 4 2
Enter the source vertex, destination vertex and the edge weight.
3 2 5
Enter the source vertex, destination vertex and the edge weight.
3 1 1
Enter the source vertex, destination vertex and the edge weight.
4 3 -3

SAMPLE OUTPUT :
Vertex Distance from Source
0                0
1                -1
2                2
3                -2
4                1

*/
