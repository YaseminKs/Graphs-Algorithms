#include <stdio.h>
#include <omp.h>

int main(){
    int n = 5;
    #pragma omp parallel for
    for( int i = 0 ; i < n ; i++ ){
        printf( "%d -> %d\n", i, ( i+1 )%n );
    }
    return 0;
}
