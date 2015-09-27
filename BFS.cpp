#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



vector<int> BFS(vector< vector<int> > &graph,int start){
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    vector<int> distances(graph.size(),-1);
    
    //Conquer the start vertex
    visited[start] = true;
    distances[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int j=0;j<graph[u].size();j++){
            int v = graph[u][j];
            if(visited[v] == false){
                visited[v] = true;
                distances[v] = distances[u] + 6;
                q.push(v);
            }
        }
    }
    
    return distances;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,m,n,start,x,y;
    vector<int> distances;
    cin>>t;
    
    while(t--){
        cin>>n>>m;
        vector< vector<int> > graph(n+1);
        vector<int> distances(n+1);
        while(m--){
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin>>start;
        distances = BFS(graph,start);
        for(int i=1;i<distances.size();i++){
            if(distances[i] != 0){
                cout<<distances[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
