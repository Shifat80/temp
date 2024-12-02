// BFS-travalsal

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int Node,Edge;
    cin>>Node>>Edge;
    vector<int>adj[Node+1];
    for(int i=0;i<Edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   vector<int>vis(Node+1,0);
   queue<int>q;
   q.push(1);
   vis[1]=1;
   while(!q.empty())
   {
       int node=q.front();
       cout<<node<<" ";
       q.pop();
       for(auto it:adj[node])
       {
           if(!vis[it])
           {
               q.push(it);
               vis[it]=1;
           }
       }
   }
    return 0;
}