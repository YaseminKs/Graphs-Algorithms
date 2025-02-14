// Basic

import java.util.Arrays;

public class Graph{
    private int[][] matrix;

    public Graph( int vertices ){
        matrix = new int[vertices][vertices];
    }

    public void addEdge( int u, int v ){
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    public void display(){
        for( int[] row : matrix ){
            System.out.println( Arrays.toString( row ) );
        }
    }

    public static void main( String[] args ){
        Graph trivial = new Graph( 1 );
        trivial.display();

        Graph g = new Graph( 3 );
        g.addEdge( 0, 1 );
        g.addEdge( 1, 2 );
        g.display();
    }
}
