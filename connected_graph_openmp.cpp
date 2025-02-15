// Connected Graph in OpenMP

#include <stdio.h>
#include <omp.h>

#define V 4

void dfs( int graph[V][V], int visited[], int start ){
    visited[start] = 1;
    #pragma omp parallel for
    for( int i = 0 ; i < V ; i++ ){
        if( graph[start][i] && !visited[i] )
            dfs( graph, visited, i );
    }
}

int main(){
    int graph[V][V] = { { 0, 1, 0, 0 },
                       { 1, 0, 1, 0 },
                       { 0, 1, 0, 1 },
                       { 0, 0, 1, 0 } };
    int visited[V] = { 0 };

    dfs( graph, visited, 0 );

    int connected = 1;
    for( int i = 0 ; i < V ; i++ )
        if( !visited[i] ) connected = 0;

    printf( "Is graph connected? %s\n", connected ? "Yes" : "No" );
    
  return 0;
}
