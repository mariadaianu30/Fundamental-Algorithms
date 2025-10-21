///implementare graf (var 2) + BFS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    queue<int> q;
    int n,m;
   /// n noduri, m muchii

    cin>>n>>m;
    vector<vector<int>> graf(n+1);
    vector<bool> viz(n+1, false);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }
    int start;
    cin>>start;
    q.push(start);              ///varianta iterativa
    viz[start]=1;
    while(!q.empty())
    {
        int nod=q.front();
        cout<<nod<<" ";
        q.pop();
        for(auto it:graf[nod])
        {
            if(viz[it]==0)
            {
                q.push(it);
                viz[it]=1;
            }
        }
    }

    return 0;
}