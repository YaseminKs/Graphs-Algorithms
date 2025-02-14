// Parallel Adjacency Matrix Initialization

#include <cuda_runtime.h>
#include <iostream>
using namespace std;

__global__ void initializeGraph( int* graph, int V ){
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if( idx < V * V ){
        graph[idx] = 0;
    }
}

int main(){
    int V = 3;
    int* d_graph;
    size_t size = V * V * sizeof( int );
    cudaMalloc( &d_graph, size );
    initializeGraph<<<1, V * V>>>( d_graph, V );
    cudaDeviceSynchronize();

    int* h_graph = new int[V * V];
    cudaMemcpy( h_graph, d_graph, size, cudaMemcpyDeviceToHost );

    // Display the graph
    for( int i = 0 ; i < V ; i++ ){
        for( int j = 0 ; j < V ; j++ ){
            cout << h_graph[i * V + j] << " ";
        }
        cout << endl;
    }

    cudaFree( d_graph );
    delete[] h_graph;
    return 0;
}
