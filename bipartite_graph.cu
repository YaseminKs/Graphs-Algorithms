// Simplified Version

#include <iostream>
#include <cuda_runtime.h>

__global__ void findMatching( int *adjMatrix, int *matchesA, int *matchesB, int numNodesA, int numNodesB ){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    // Ensure we're within bounds of A and B
    if( idx < numNodesA ){
        for( int j = 0 ; j < numNodesB ; ++j ){
            // Check if an edge exists between A[idx] and B[j]
            if( adjMatrix[idx * numNodesB + j] == 1 ){
                // Check if B[j] is not already matched, then match A[idx] with B[j]
                if( matchesB[j] == -1 ){
                    matchesA[idx] = j;
                    matchesB[j] = idx;
                    return;
                }
            }
        }
    }
}

int main(){
    int numNodesA = 4;  // Number of nodes in set A
    int numNodesB = 4;  // Number of nodes in set B

    // Example adjacency matrix (1 means an edge exists, 0 means no edge)
    int adjMatrix[] = {
        1, 0, 1, 0,
        0, 1, 1, 0,
        1, 1, 0, 1,
        0, 0, 1, 1
    };

    int *d_adjMatrix, *d_matchesA, *d_matchesB;
    int *matchesA = new int[numNodesA];
    int *matchesB = new int[numNodesB];

    // Initialize match arrays (-1 means no match)
    for( int i = 0 ; i < numNodesA ; ++i ){
        matchesA[i] = -1;
    }
  
    for( int i = 0 ; i < numNodesB ; ++i ){
        matchesB[i] = -1;
    }

    // Allocate memory on the device
    cudaMalloc( &d_adjMatrix, numNodesA * numNodesB * sizeof( int ) );
    cudaMalloc( &d_matchesA, numNodesA * sizeof( int ) );
    cudaMalloc( &d_matchesB, numNodesB * sizeof( int ) );

    // Copy data to device
    cudaMemcpy( d_adjMatrix, adjMatrix, numNodesA * numNodesB * sizeof( int ), cudaMemcpyHostToDevice );
    cudaMemcpy( d_matchesA, matchesA, numNodesA * sizeof( int ), cudaMemcpyHostToDevice );
    cudaMemcpy( d_matchesB, matchesB, numNodesB * sizeof( int ), cudaMemcpyHostToDevice );

    // Define block and grid sizes
    int blockSize = 256;  // Number of threads per block
    int gridSize = ( numNodesA + blockSize - 1 ) / blockSize;  // Number of blocks needed

    // Launch the kernel to find matching
    findMatching<<<gridSize, blockSize>>>( d_adjMatrix, d_matchesA, d_matchesB, numNodesA, numNodesB );

    // Copy results back to host
    cudaMemcpy( matchesA, d_matchesA, numNodesA * sizeof( int ), cudaMemcpyDeviceToHost );
    cudaMemcpy( matchesB, d_matchesB, numNodesB * sizeof( int ), cudaMemcpyDeviceToHost );

    // Display the result (matches)
    std::cout << "Matches from A to B:\n";
    for( int i = 0 ; i < numNodesA ; ++i ){
        if( matchesA[i] != -1 ){
            std::cout << "A[" << i << "] is matched to B[" << matchesA[i] << "]\n";
        }else{
            std::cout << "A[" << i << "] has no match\n";
        }
    }

    // Cleanup
    cudaFree( d_adjMatrix );
    cudaFree( d_matchesA );
    cudaFree( d_matchesB );
    delete[] matchesA;
    delete[] matchesB;

    return 0;
}
