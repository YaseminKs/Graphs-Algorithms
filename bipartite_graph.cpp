// Bipartite using BFS

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

bool isBipartite( vector<vector<int>>& graph, int src ){
    int V = graph.size();
    vector<int> color( V, -1 );
    color[src] = 1;

    queue<int> q;
    q.push( src );

    while( !q.empty() ){
        int u = q.front();
        q.pop();

        for( int v : graph[u] ){
            if( color[v] == -1 ){
                color[v] = 1 - color[u];
                q.push( v );
            }else if( color[v] == color[u] ){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {
        { 1, 3 },
        { 0, 2 },
        { 1, 3 },
        { 0, 2 }
    };

    cout << "Is the graph bipartite? " << ( isBipartite( graph, 0 ) ? "Yes" : "No" ) << endl;
    return 0;
}
