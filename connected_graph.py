from collections import defaultdict

def is_connected( graph, start ):
    visited = set()
    def dfs( v ):
        visited.add( v )
        for neighbor in graph[v]:
            if neighbor not in visited:
                dfs( neighbor )
    dfs( start )
    return len( visited ) == len( graph )

graph = { 0: [1, 2], 1: [0, 2], 2: [0, 1] }
print( "Is graph connected?", is_connected( graph, 0 ) )
