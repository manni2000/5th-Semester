#include <bits/stdc++.h>
using namespace std;
#define Node 10

vector<pair<int, pair<int, int>>> adj;
vector<int> dis(Node + 1, 1e9);
int ct = 0;
void Bellman_ford(int src)
{
  dis[src] = 0;
  for (int i = 1; i < Node; i++)
  {
    for (int j = 0; j < adj.size(); j++)
    {
      if (dis[adj[j].first] != 1e9 && dis[adj[j].second.first] > dis[adj[j].first] + adj[j].second.second)
      {
        ct += 2;
        dis[adj[j].second.first] = dis[adj[j].first] + adj[j].second.second;
      }
      ct += 1;
    }
  }
}
bool checkNegCycle()
{
  int flag = 0;
  for (int j = 0; j < adj.size(); j++)
  {
    if (dis[adj[j].first] != 1e9 && dis[adj[j].second.first] > dis[adj[j].first] + adj[j].second.second)
    {
      dis[adj[j].second.first] = dis[adj[j].first] + adj[j].second.second;
      flag = 1;
    }
  }
  if (flag)
    return true;
  return false;
}
int main()
{
  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj.push_back({u, {v, w}});
  }
  int src = 1;
  Bellman_ford(1);
  if (checkNegCycle())
    cout << "Negative cycle is Present " << endl;
  else
    cout << "Negative cycle is not Present " << endl;
  for (int i = 1; i <= Node; i++)
  {
    cout << "Distance of " << i << " from " << src << " is " << dis[i] << endl;
  }

  cout << "Total no. of assignment and comparison operator is " << ct<< endl;
}