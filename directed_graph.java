// Directed Graph with Edge Addition

import java.util.Arrays;

public class DirectedGraph{
    private int[][] matrix;

    public DirectedGraph( int vertices ){
        matrix = new int[vertices][vertices];
    }

    public void addEdge( int u, int v ){
        matrix[u][v] = 1; // Directed edge from u to v
    }

    public void display(){
        for( int[] row : matrix ){
            System.out.println( Arrays.toString( row ) );
        }
    }

    public static void main( String[] args ){
        DirectedGraph g = new DirectedGraph( 3 );
        g.addEdge( 0, 1 );
        g.addEdge( 1, 2 );
        g.display();
    }
}
