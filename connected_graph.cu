// Connected Graph in CUDA

#include <stdio.h>
#include <cuda.h>

__global__ void checkConnectivity( int *graph, int *visited, int V ){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if( idx < V && visited[idx] ){
        for( int j = 0 ; j < V ; j++ ){
            if( graph[idx * V + j] && !visited[j] )
                visited[j] = 1;
        }
    }
}

int main(){
    int V = 4;
    int graph[16] = { 0, 1, 0, 0,
                     1, 0, 1, 0,
                     0, 1, 0, 1,
                     0, 0, 1, 0 };
    int visited[4] = { 1, 0, 0, 0 };

    int *d_graph, *d_visited;
    cudaMalloc( &d_graph, V * V * sizeof( int ) );
    cudaMalloc( &d_visited, V * sizeof( int ) );

    cudaMemcpy( d_graph, graph, V * V * sizeof( int ), cudaMemcpyHostToDevice );
    cudaMemcpy( d_visited, visited, V * sizeof( int ), cudaMemcpyHostToDevice );

    checkConnectivity<<<1, V>>>(d_graph, d_visited, V);

    cudaMemcpy( visited, d_visited, V * sizeof( int ), cudaMemcpyDeviceToHost );

    bool connected = true;
    for( int i = 0 ; i < V ; i++ )
        if( !visited[i]) connected = false;

    printf( "Is graph connected? %s\n", connected ? "Yes" : "No" );

    cudaFree( d_graph );
    cudaFree( d_visited );
    
  return 0;
}
