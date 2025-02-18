# Python code for cycle graph

def cycle_graph(n):
    graph = {i: [(i+1) % n] for i in range(n)}
    graph[n-1].append(0)
   return graph
