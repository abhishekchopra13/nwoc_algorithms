#include<bits/stdc++.h> 
using namespace std; 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 
void DFSUtil(int u, vector<int> adj[], 
					vector<bool> &visited) 
{ 
	visited[u] = true; 
	cout << u << " "; 
	for (int i=0; i<adj[u].size(); i++) 
		if (visited[adj[u][i]] == false) 
			DFSUtil(adj[u][i], adj, visited); 
} 
void DFS(vector<int> adj[], int V) 
{ 
	vector<bool> visited(V, false); 
	for (int u=0; u<V; u++) 
		if (visited[u] == false) 
			DFSUtil(u, adj, visited); 
} 

int main() 
{ 
	/*#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     freopen("error.txt","w",stderr);
     #endif
    */

	int V , edge ;
	cout<<"Enter number of vertices and number of edges respectively:-";
	cin>>V>>edge;

    vector<int> *adj = new vector<int>[V+1];

	for(int i=0;i<edge;++i)
	{
		cout<<"Enter next adjacent pair";
		int x,y;
		cin>>x>>y;
		addEdge(adj,x,y);
	}
	cout<<"The order of the depth first search traversal is ";
	DFS(adj, V); 
	return 0; 
} 