from collections import deque


class Vertex:
    def __init__(self, name, edges):
        self.name = name
        self.edges = edges


class Graph:
    def __init__(self, vertices=[]):
        if vertices:
            self.graph = {vertex.name: vertex.edges for vertex in vertices}
        else:
            self.graph = {}


    def add(self, Vertex):
        self.graph[Vertex.name] = Vertex.edges


    def get_neighbors(self, name):
        return self.graph[name]


    def bfs(self, node_name):
        queue = deque()
        discovered = []
        queue.append(node_name)
        discovered.append(node_name)
        # While queue isn't empty
        while queue:
            node_name = queue.popleft() # Dequeue
            neighbors = self.get_neighbors(node_name)
            for neighbor in neighbors:
                if neighbor not in discovered:
                    queue.append(neighbor)
                    discovered.append(neighbor)


vertices = [Vertex('bob', ['alice', 'george']),
            Vertex('george', [])]
g = Graph(vertices)
print(g.get_neighbors('bob'))
g.add(Vertex('alice', ['bob', 'tom']))
g.add(Vertex('tom', ['bob']))
print(g.get_neighbors('alice'))
g.bfs('alice')
