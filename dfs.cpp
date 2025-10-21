///reprezentare graf in c++

///1.   unordered_map<int, vector<int>>-- pentru nodul 1 ii corescunde un array cu nodurile la care se leaga
///2.   vector<vector<int>> --- pe pozitia 2 din vector punem o lista cu vecinii nodului 2
///3.   1 5 10 15
///     0 1 2  3            ---inlocuim valorile initiale cu indicii corespunzatori


///Se da un nod de start. Sa se determine nodurile accesibile din acesta.(exista un lant intre start si nodul verificat)
/// Reprezentare in C++: stack<int>
///plecam din nodul de start, il punem in stiva si dupa ii dam pop(il marcam ca vizitat).
///Mergem in lista de adiacenta a nodului vizitat si o punem pe stiva. Dam pop ultimului nod si il marcam vizitat. Repetam algoritmul.



///implementare graf (var 2) + DFS
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int nod, vector<vector<int>>& graf, vector<bool>& viz)           ///recursiv
{
    viz[nod]=true;
    cout<<nod<<" ";
    for(auto it:graf[nod])
    {
        if(viz[it]==false)
            dfs(it, graf, viz);
    }
}
int main(){

    stack<int> st;
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
    // st.push(start);              ///varianta iterativa
    // viz[start]=1;
    // while(!st.empty())
    // {
    //     int nod=st.top();
    //     cout<<nod<<" ";
    //     st.pop();
    //     for(auto it:graf[nod])
    //     {
    //         if(viz[it]==0)
    //         {
    //             st.push(it);
    //             viz[it]=1;
    //         }
    //     }
    // }
    dfs(start, graf, viz);
    return 0;
}