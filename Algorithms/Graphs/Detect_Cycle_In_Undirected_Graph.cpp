// C++ program to detect cycle in an undirected graph using BFS. 
#include <bits/stdc++.h> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

bool isCyclicConntected(vector<int> adj[], int VertexToBeVisited,int NoOfVertices, vector<bool>& visited) 
{ 
	// Set parent vertex for every vertex as -1. 
	vector<int> parent(NoOfVertices, -1); 

	// Create a queue for BFS 
	queue<int> queue; 

	// Mark the current node as visited and enqueue it 
	visited[VertexToBeVisited] = true; 
	queue.push(VertexToBeVisited); 

	while (!queue.empty()) { 

		// Dequeue a vertex from queue and print it 
		int u = queue.front(); 
		queue.pop(); 

		for (auto v : adj[u]) 
		{ 
			if (!visited[v]) 
			{ 
				visited[v] = true; 
				queue.push(v); 
				parent[v] = u; 
			} 
			else if (parent[u] != v) 
				return true; 
		} 
	} 
	return false; 
} 

bool isCyclicDisconntected(vector<int> adj[], int V) 
{ 
	// Mark all the vertices as not visited 
	vector<bool> visited(V, false); 
	for (int i = 0; i < V; i++) 
		if (!visited[i] && isCyclicConntected(adj, i,V, visited)) 
			return true; 
	return false; 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	cout<<"enter the number of vertices : ";
	int no_of_variables ;
	cin>>no_of_variables;
	//adj[V] is 2D vector to store the connection between 2 vertices
	int vertex1,vertex2;
	vector<int> adj[no_of_variables]; 
	do{
		char ch;
		cout<<"Enter Edge Details :\n";
		cout<<"Enter Vertex 1 : ";
		cin>>vertex1;
		cout<<"Enter Vertex 2 : ";
		cin>>vertex2;
		addEdge(adj,vertex1,vertex2);
		cout<<"wanna add more edges(y/n):";
		cin>>ch;
	}while(ch!='y');
	if (isCyclicDisconntected(adj, no_of_variables)) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
