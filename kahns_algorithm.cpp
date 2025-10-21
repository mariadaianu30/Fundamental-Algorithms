/// Kahn's Algorithm for Topological Sorting


///We use the BFS logic + repeatedly finding vertices with no incoming edges
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void KahnsAlgorithm(int n, vector<vector<int>>& adj)
{
   
    vector<int> degree(n+1,0);          ///we calculate the internal degree for each node
    for(int i=0;i<n;i++)
        {
            for (auto it : adj[i]) {
            degree[it]++;
        }
        }
    vector<int> topo;
    queue<int> q;
    for(int i=0;i<n;i++)            ///first, we want to push all of the nodes with no incoming vertices into the queue
    {
        if(degree[i]==0)
            q.push(i);
    }
    while(!q.empty())               ///then we simulate a bfs algorithm 
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node])    ///for each outgoing edge from the removed node, decrement the in-degree of the destination node by 1.
        {
            degree[it]--;
            if(degree[it]==0)       ///the only difference is that we push the nodes in the queue only when they reach the in-degree of 0
                q.push(it);
        }
    }
        if(topo.size()!=n)          ///if the graph contains a cycle it cannot be topologically sorted
            {
                cout<<"The graph contains a cycle!";
            }
        else
        {
            cout<<"The topological order is:";
            for(auto i: topo)
                cout<<i<<" ";

        }

}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);

    }

    KahnsAlgorithm(n,graph);
  
    return 0;
}