// Basic

#include <iostream>
using namespace std;

class Graph{
    int V;
    int** adj;

public:
    Graph( int vertices ){
        V = vertices;
        adj = new int*[V];
        for( int i = 0 ; i < V ; i++ ){
            adj[i] = new int[V]{ 0 };
        }
    }

    void addEdge( int u, int v ){
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void display(){
        for( int i = 0 ; i < V ; i++ ){
            for( int j = 0 ; j < V ; j++ ){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph(){
        for( int i = 0 ; i < V ; i++ ) delete[] adj[i];
        delete[] adj;
    }
};

int main(){
    Graph trivial( 1 );
    trivial.display();

    Graph g( 3 );
    g.addEdge( 0, 1 );
    g.addEdge( 1, 2 );
    g.display();

    return 0;
}
