///used for finding the shortest path in a maze
/// we use the bfs algorithm for implementation

///condition in the algo:
    ///the cell is free
    ///the cell was not visited
    ///we must not leave the matrix


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};      ///we declare the arrays for moving in the matrix
int dy[4] = {0, 0, -1, 1};


int leeAlgorithm(vector<vector<int>> matrix, pair<int,int> src, pair<int,int> dest){
    
    int n=matrix.size();        
    int m=matrix[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));            ///we initialize a visited boolean matrix where we mark which node we have visited alread so we don't add it to the stack again
    vector<vector<int>> dist(n, vector<int>(m, -1));                    /// the dist matrix is used for real time distance tracker
    
    queue<pair<int,int>> q;
    q.push(src);
    visited[src.first][src.second]=true;                                ///we simulate a breadth first search in our algo 
    dist[src.first][src.second]=0;

    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(x==dest.first && y==dest.second)         ///if we reach the wanted destination we stop the algorithm and exit the loop
        {
            return dist[x][y];
        }

        for(int i=0;i<4;i++)                        ///if not, we treat every neighbour in the matrix of the first vertex extracted from the queue(basically the last vertex of the road to the dest)
        {
            int nx=x+dx[i];
            int ny=y+ dy[i];
            if(nx>=0 && nx<n &&  ny>=0 && ny<m && matrix[nx][ny]==0 && !visited[nx][ny] )           ///conditions for a verified vertex
                {
                    visited[nx][ny]=true;
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});                                                                ///if the vertex respects all the conditions, we mark it as visited, we increase the distance and we push it into the queue
                }
        }
    }
    return -1;
}
    
    int main()
{
   
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++)
        { for(int j=0;j<m;j++)
            cin>>matrix[i][j];
        }

    pair<int,int> src;
    pair<int,int> dest;

    cout<<"Select the starting point: \n";
    cin>>src.first>>src.second;
    cout<<"Select the destination point: \n";
    cin>>dest.first>>dest.second;

    int result = leeAlgorithm(matrix, src, dest);

    if(result != -1)
        cout << "Shortest path length: " << result << endl;
    else
        cout << "No path exists!" << endl;

    return 0;

}