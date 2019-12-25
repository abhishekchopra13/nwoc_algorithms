
/* Prim's Algorithm for finding Minimum Spanning Tree 

Sample Input is already given in main function:

        graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

Sample Output:

Edge  Value
1 - 0   2
2 - 1   3
3 - 0   6
4 - 1   5
*/
#include <bits/stdc++.h>
using namespace std;

//V is the number of vertices
#define V 5

//Function for finding MST using Prims Algorithm

void primMST(int graph[V][V])
{
    //parent is used to store the index position
    //key is used to store the value 
 
    int parent[V],key[V];

    //All key values are initialized to maximum integer value

    for(int i=0;i<V;i++)
        key[i]= INT_MAX;
    


    for(int u = 1; u<V; u++)
    {
        for(int row=0;row<V;row++)
        {
            if(graph[row][u] && graph[row][u]<key[u])
            {
                key[u] = graph[row][u];
                parent[u] = row;
            }
        }
    }
    cout<<"Edge\tValue\n";
    for(int m=1;m<V;m++)
    {
        cout<<m<<" - "<<parent[m]<<" \t "<<key[m]<<"\n";
    }
}
int main()
{
    // Variable graph contains the adjacency matrix of a graph
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}


