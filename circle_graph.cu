#include <stdio.h>

__global__ void cycleGraph( int n ){
    int i = threadIdx.x;
    printf( "%d -> %d\n", i, ( i+1 )%n );
}

int main(){
    int n = 5;
    cycleGraph<<<1, n>>>( n );
    cudaDeviceSynchronize();
    return 0;
}
