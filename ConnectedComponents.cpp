#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void BFSFindComponent(vector< vector<int> > &graph,int start, vector<int> &componentnums, int componentnum){
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    vector<int> distances(graph.size(),-1);
    vector<int> findablevertices;
    //Conquer the start vertex
    visited[start] = true;
    distances[start] = 0;
    q.push(start);
    componentnums[start] = componentnum;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int j=0;j<graph[u].size();j++){
            int v = graph[u][j];
            if(visited[v] == false){
                visited[v] = true;
                distances[v] = distances[u] + 6;
                q.push(v);
                componentnums[v] = componentnum;
            }
        }
    }
}

vector<int> ConnectedComponents(vector< vector<int> > &graph){
    vector<int> componentnums(graph.size(),-1);
    int componentnum = -1;
    for(int i=1;i<graph.size();i++){
        if(componentnums[i] == -1){
            componentnum++;
            BFSFindComponent(graph,i,componentnums,componentnum);
        }
    }
    return componentnums;    
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
        vector<int> componentnums = ConnectedComponents(graph);
        for(int i=1;i<componentnums.size();i++){
            cout<<componentnums[i]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
