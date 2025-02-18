#include <iostream>
#include <omp.h>

void findMatching( int* adjMatrix, int* matchesA, int* matchesB, int numNodesA, int numNodesB ){
    // Initialize match arrays (-1 means no match)
    #pragma omp parallel for
    for( int i = 0 ; i < numNodesA ; ++i ){
        matchesA[i] = -1;
    }
    
    #pragma omp parallel for
    for( int i = 0 ; i < numNodesB ; ++i ){
        matchesB[i] = -1;
    }

    // Try to match nodes in A to B
    #pragma omp parallel for
    for( int i = 0 ; i < numNodesA ; ++i ){
        for( int j = 0 ; j < numNodesB ; ++j ){
            // Check if an edge exists between A[i] and B[j]
            if( adjMatrix[i * numNodesB + j] == 1 ){
                // If B[j] is not already matched, match A[i] with B[j]
                if( matchesB[j] == -1 ){
                    matchesA[i] = j;
                    matchesB[j] = i;
                    break;
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

    int* matchesA = new int[numNodesA];
    int* matchesB = new int[numNodesB];

    // Find matching
    findMatching( adjMatrix, matchesA, matchesB, numNodesA, numNodesB );

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
    delete[] matchesA;
    delete[] matchesB;

    return 0;
}

// for compiling:
// g++ -fopenmp -o bipartite_matching bipartite_matching.cpp
