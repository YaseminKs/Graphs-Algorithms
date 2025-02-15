// Parallel Directed Graph Initialization
// CPU Parallel

#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int V = 3;
    int graph[V][V] = {0};

    // Initialize graph with parallel threads
    #pragma omp parallel for collapse( 2 )
    for( int i = 0 ; i < V ; i++ ){
        for( int j = 0 ; j < V ; j++ ){
            graph[i][j] = 0;
        }
    }

    // Add directed edges
    graph[0][1] = 1; // 0 -> 1
    graph[1][2] = 1; // 1 -> 2

    // Display the graph
    for( int i = 0 ; i < V ; i++ ){
        for( int j = 0 ; j < V ; j++ ){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
