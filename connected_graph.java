// Connected Graph in Java
import java.util.*;

class ConnectedGraphJava{
    private int V;
    private LinkedList<Integer> adj[];

    ConnectedGraphJava( int v ){
        V = v;
        adj = new LinkedList[v];
        for( int i = 0 ; i < v ; ++i )
            adj[i] = new LinkedList();
    }

    void addEdge( int v, int w ){
        adj[v].add( w );
        adj[w].add( v );
    }

    void DFSUtil( int v, boolean visited[] ){
        visited[v] = true;
        for( int n : adj[v] )
            if( !visited[n] )
                DFSUtil( n, visited );
    }

    boolean isConnected(){
        boolean visited[] = new boolean[V];
        DFSUtil( 0, visited );
        for( boolean v : visited )
            if( !v ) return false;
        return true;
    }

    public static void main( String args[] ){
        ConnectedGraphJava g = new ConnectedGraphJava( 4 );
        g.addEdge( 0, 1 );
        g.addEdge( 1, 2 );
        g.addEdge( 2, 3 );

        System.out.println( "Is graph connected? " + g.isConnected() );
    }
}
