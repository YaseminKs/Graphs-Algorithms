class Graph
  def initialize
    @adj_list = Hash.new { |h, k| h[k] = [] }
  end

  def add_edge( u, v )
    @adj_list[u] << v
    @adj_list[v] << u
  end

  def connected?
    visited = {}
    dfs( 0, visited )
    visited.size == @adj_list.keys.size
  end
  
  private
  
  def dfs( node, visited )
    visited[node] = true
    @adj_list[node].each { |neighbor| dfs(neighbor, visited) unless visited[neighbor] }
  end
end

g = Graph.new
[ [0,1],[1,2],[2,3] ].each { |u,v| g.add_edge(u,v) }
puts "Is graph connected? #{g.connected?}"
