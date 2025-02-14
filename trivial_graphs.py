# Basic 
# Best for simplicity and experimentation

class Graph:
    def __init__( self, vertices ):
        self.V = vertices
        self.graph = [[0]*vertices for _ in range( vertices )]

    def add_edge( self, u, v ):
        self.graph[u][v] = 1
        self.graph[v][u] = 1

    def display( self ):
        for row in self.graph:
            print( row )


# Trivial graph with 1 vertex
g = Graph( 1 )
g.display()

# Simple 3-node graph
g3 = Graph( 3 )
g3.add_edge( 0, 1 )
g3.add_edge( 1, 2 )
g3.display()
