// Directed Graph Class

#include <iostream>
using namespace std;

class DirectedGraph{
    int V;
    int** adj;

public:
    DirectedGraph( int vertices ){
        V = vertices;
        adj = new int*[V];
        for( int i = 0 ; i < V ; i++ ){
            adj[i] = new int[V]{0};
        }
    }

    void addEdge( int u, int v ){
        adj[u][v] = 1; // Directed edge
    }

    void display(){
        for( int i = 0 ; i < V ; i++ ){
            for( int j = 0 ; j < V ; j++ ){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~DirectedGraph(){
        for( int i = 0 ; i < V ; i++ ) delete[] adj[i];
        delete[] adj;
    }
};

int main(){
    DirectedGraph g( 3 );
    g.addEdge( 0, 1 );
    g.addEdge( 1, 2 );
    g.display();
    return 0;
}
