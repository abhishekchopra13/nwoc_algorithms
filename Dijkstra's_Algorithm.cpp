/*

	Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm) is an algorithm for finding the 
	shortest paths between nodes in a weighted graph, which may represent, for example, mobile or road networks.

	It can be implemented in C++ using  :
	1) Adjacency matrix representation
	2) Adjacency List representation (using vector STL of C++)
	3) Set STL of C++ 
	4) PriorityQueue STL of C++

	This code is implementation	of Dijkstra's algorithm using Adjacency list representation for Undirected weighted graph.

	When to use Dijkstra's algorithm and Floyd Warshall algorithm ?
	-> Dijkstra's algorithm is for single source and multiple destinations .
	-> Floyd Warshall algorithm is for multiple sources and multiple destinations .

*/


/*


SAMPLE OUTPUT :


Enter number of vertices
4

Enter number of edges
5

Undirected weighted graph

Enter all edges one by one 
Format for input : vertex1 vertex2 weight
1 2 2
1 3 10
1 4 4
2 3 2
4 2 15

Enter the source vertex
2

    Source    Destination   Shortest Distance
         2         1                   2
         2         2                   0
         2         3                   2
         2         4                   6


*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 1111
#define INF 999999999
vector< pair<int, int> >v[MAXN];

vector<int> djikstras(int source, int no_of_vertices) {
	vector<int> dist(no_of_vertices, INF);
	set< pair<int, int> > queue;
	vector<bool> visited(no_of_vertices, false);
	dist[source] = 0;
	visited[source] = true;
	queue.insert(make_pair(dist[source], source));

	while(!queue.empty()) {
		pair<int, int> front_p = *(queue.begin());
		queue.erase(queue.begin());
		int cur_dist = front_p.first;
		int node = front_p.second;

		for(int i=0; i<v[node].size(); i++) {
			int to = v[node][i].first;
			int weight = v[node][i].second;
			if(dist[to] > cur_dist + weight) {
				if(queue.find(make_pair(dist[to], to)) != queue.end()) {
					queue.erase(make_pair(dist[to], to));
				}
				dist[to] = cur_dist + weight;
				queue.insert(make_pair(dist[to], to));
			}
		}	
	}
	return dist;
}

int main() {
	cout<<"\nEnter number of vertices\n";
	int no_of_vertices; cin >> no_of_vertices;

	cout<<"\nEnter number of edges\n";
	int no_of_edges; cin >> no_of_edges;

	/*
		Input the edges of undirected weighed graph  
		Format for input :
		vertex1 vertex2 weight
	*/

	cout<<"\nUndirected weighted graph ";

	cout<<"\nEnter all edges one by one "
		<<"\nFormat for input : vertex1 vertex2 weight\n";
	for(int i=0; i<no_of_edges; i++) {
		int vertex1, vertex2, weight;
		cin >> vertex1 >> vertex2 >> weight;
		vertex1--, vertex2--;
		v[vertex1].push_back(make_pair(vertex2, weight));
		v[vertex2].push_back(make_pair(vertex1, weight));
	}

	/*
		Source vertex is that vertex from where shortest distance to all other vertices is to be found
	*/
	
	cout<<"\nEnter the source vertex\n";
	int source; cin >> source;
	source --;
	vector<int> dist = djikstras(source, no_of_vertices);

	cout<<"\n";
	cout<<setw(10)<<"Source"<<setw(15)<<"Destination"<<setw(20)<<"Shortest Distance";
	cout<<"\n";
	for(int i=0; i<no_of_vertices; i++) {
		cout<<setw(10)<<source+1;
		cout <<setw(10)<<i + 1 <<setw(20)<< dist[i] << "\n";
	}
}

