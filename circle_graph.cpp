#include <iostream>

using namespace std;

int main() {
    int n = 5;
    for( int i = 0 ; i < n ; i++ ){
        cout << i << " -> " << ( i + 1 ) % n << endl;
    }
    return 0;
}
