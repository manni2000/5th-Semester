#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> makeRandomGraph(int n)
{
    vector<vector<int>> bfsgraph(n, vector<int>(n));
    srand(time(NULL));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (rand() & 1)
                bfsgraph[x][y] = 1;
            else
                bfsgraph[x][y] = 0;
        }
    }
    return bfsgraph;
}

vector<int> BFS(int node, vector<vector<int>> graph, int n)
{

    vector<int> traversal;
    vector<int> visited(n, 0);
    queue<int> ans;
    ans.push(node);
    visited[node] = 1;
    while (!ans.empty())
    {
        int currNode = ans.front();
        ans.pop();
        traversal.push_back(currNode);
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = true;
                ans.push(i);
            }
        }
    }

    return traversal;
}

int main(int argc, char const *argv[])
{
    int n = 10;
    vector<vector<int>> bfsgraph;
    vector<int> traversal;
    bfsgraph = makeRandomGraph(n);

    ofstream fout("./graph.txt");
    fout<<"Adjacent edges\n\n";

    for (vector<int> it : bfsgraph)
    {
        for (int x : it)
        {
            fout << x << " ";
        }
        fout << "\n";
    }
    traversal = BFS(0,bfsgraph,n);

    fout<<"\nBFS traversal : ";
    for(auto it : traversal)
        fout<<it<<" ";

    fout.close();
    return 0;
}