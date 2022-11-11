#include<bits/stdc++.h> 
using namespace std;


class Edge
{
public:
    int src;
    int dest;
    int weight;

};

bool compare(Edge e1, Edge e2)
{
    return e1.weight<e2.weight;
}

int getParent(int v,int*parent)
{
    if(parent[v]==v)
        return v;
    return getParent(parent[v],parent);
}

Edge* kruskals(Edge* edges, int n, int E)
{
    //Sorted the edges array in increasing order
    sort(edges,edges+E,compare);

    Edge*output=new Edge[n-1];
    int*parent=new int[n];
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }

    int count=0,i=0;
    while(count<n-1)
    {
        //Check the topmost parent of v1 and v2 where v1 and v2 are the vertices of the current edge

        Edge currentEdge=edges[i];
        int srcParent=getParent(currentEdge.src,parent);
        int destParent=getParent(currentEdge.dest,parent);

        if(srcParent!=destParent)
        {
            output[count]=currentEdge;
            count+=1;
            parent[srcParent]=destParent;
        }
        i++;

    }

    return output;  

}


void solve()
{
    int n,E;
    cin>>n>>E;

    Edge* edges=new Edge[E];

    for(int i=0; i<E; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
    }

    Edge* output=kruskals(edges,n,E);

    for(int i=0; i<n-1; i++)
    {
        if(output[i].src<output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}