//Graph Traversal Algorithm
//Language Used: C++
//Breadth First Traversal algorithm to traverse all nodes of a graph considering only one component in graph
//Output: This algorithm will give nodes visited in breadth first manner and distance of each node from source.
//author:namanvats
#include<bits/stdc++.h>
using namespace std;
#define MAX5 100010
#define pb push_back
int dist[MAX5];
bool visit[MAX5];
vector<int> vec[MAX5];
queue<int> q;
void bfs(int src)
{
    memset(visit,0,sizeof(visit));
    dist[src]=0;    
    q.push(src);
    while(q.size()!=0)
    {
        int p=q.front();
        cout<<p<<" ";
        q.pop();
        visit[p]=1;
        for(int i=0;i<vec[p].size();i++)
        {
            if(visit[vec[p][i]]==0)
            {
                q.push(vec[p][i]);
                dist[vec[p][i]]=dist[p]+1;
                visit[vec[p][i]]=1;
            }
        }
    }
}
int main()
{
    //Nodes are numbered from 1
    cout<<"Enter number of Nodes and Edges"<<'\n';
    int nodes,edges;
    cin>>nodes>>edges;
    cout<<"Enter edges between nodes"<<'\n';
    for(int i=0;i<edges;i++)
    {
        //undirected edges
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    cout<<"Enter Source node"<<'\n';
    int src;
    cin>>src;
    cout<<"The nodes are:"<<'\n';
    bfs(src);
    cout<<'\n';
    cout<<"Distance of each node starting from source:"<<'\n';
    for(int i=1;i<=nodes;i++)
    {
        cout<<"Distance of node"<<" "<<i<<":"<<" "<<dist[i]<<"\n";
    }
return 0;
}
