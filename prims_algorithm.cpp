#include <bits/stdc++.h>
using namespace std;
#define V 5

void primMST(int graph[V][V])
{
    bool mstSet[V];
    int parent[V],key[V];

    for(int i=0;i<V;i++)
    {
        mstSet[i] = false;
        key[i]= INT_MAX;
    }


    for(int u = 1; u<V; u++)
    {
        for(int i=0;i<V;i++)
        {
            if(graph[i][u]&&mstSet[i] == false && graph[i][u]<key[u])
            {
                key[u] = graph[i][u];
                parent[u] = i;
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


