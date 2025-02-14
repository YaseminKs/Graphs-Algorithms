// Parallel Graph Initialization

#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    int V = 3;
    int graph[V][V] = {0};

    #pragma omp parallel for collapse( 2 )
    for( int i = 0 ; i < V ; i++ ){
        for( int j = 0 ; j < V ; j++ ){
            graph[i][j] = 0;
        }
    }

    // Display the trivial graph
    for( int i = 0 ; i < V ; i++ ){
        for( int j = 0 ; j < V ; j++ ){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
