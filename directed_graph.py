# Simple Directed Graph

class DirectedGraph:
    def __init__( self, vertices ):
        self.V = vertices
        self.graph = [[0]*vertices for _ in range( vertices )]

    def add_edge( self, u, v ):
        self.graph[u][v] = 1  # Directed edge from u to v

    def display( self ):
        for row in self.graph:
            print( row )


# Example
g = DirectedGraph( 3 )
g.add_edge( 0, 1 )
g.add_edge( 1, 2 )
g.display()
