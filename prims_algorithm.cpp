#include <bits/stdc++.h>
using namespace std;
#define V 5

void primMST(int graph[V][V])
{
    
    int parent[V],key[V];

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

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}


