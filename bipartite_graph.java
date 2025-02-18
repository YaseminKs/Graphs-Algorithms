// Bipartite using BFS

import java.util.*;

public class BipartiteGraph{
    static boolean isBipartite( int[][] graph, int src ){
        int[] color = new int[graph.length];
        Arrays.fill( color, -1 );

        color[src] = 1;
        Queue<Integer> queue = new LinkedList<>();
        queue.add( src );

        while( !queue.isEmpty() ){
            int u = queue.poll();

            for( int v : graph[u] ){
                if( color[v] == -1 ){
                    color[v] = 1 - color[u];
                    queue.add( v );
                }else if( color[v] == color[u] ){
                    return false;
                }
            }
        }
        return true;
    }

    public static void main( String[] args ){
        int[][] graph = {
            { 1, 3 },
            { 0, 2 },
            { 1, 3 },
            { 0, 2 }
        };

        System.out.println( "Is the graph bipartite? " + isBipartite( graph, 0 ) );
    }
}
