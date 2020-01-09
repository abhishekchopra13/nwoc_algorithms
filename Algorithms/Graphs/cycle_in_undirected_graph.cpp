// A C++ Program to detect cycle in an undirected graph
// Language Used: C++
// Output: This algorithm will give the output that whether the graph has cycle or not
// Sample Input:
// Enter the number of vertices
/*   5
   Enter the number of edges
    5
    Enter edge no 1
    1 0
    Enter edge no 2
    0 2
    Enter edge no 3
    2 1
    Enter edge no 4
    0 3
    Enter edge no 5
    3 4     */
//  Sample output:
//  Graph contains cycle
// Sample Output:
// The value of nCr for numbers 5 and 3 is 10
// Author:Aditya Kothari

#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();   // returns true if there is a cycle
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, v))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
        if (!visited[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, visited, -1))
             return true;

    return false;
}

// Driver program to test above functions
int main()
{
    int n,m,a,b,i;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;
    Graph g1(n);
    for(i=0;i<m;i++)
    {
        cout<<"Enter edge no "<<i+1<<"\n";
        cin>>a>>b;
        g1.addEdge(a,b);
    }
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
    return 0;
}
