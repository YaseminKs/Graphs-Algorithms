# Python code to check if a given graph is Bipartite using BFS
from collections import deque

def is_bipartite( graph, start ):
    color = {}
    for node in graph:
        color[node] = -1  # -1 indicates no color assigned yet

    color[start] = 0
    queue = deque( [start] )

    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if color[v] == -1:
                color[v] = 1 - color[u]  # Assign opposite color
                queue.append( v )
            elif color[v] == color[u]:
                return False
    return True

# Example usage
graph = {
    0: [1, 3],
    1: [0, 2],
    2: [1, 3],
    3: [0, 2]
}

print( "Is the graph bipartite?", is_bipartite( graph, 0 ) )
