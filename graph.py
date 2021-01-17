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


vertices = [Vertex('bob', ['alice', 'george'])]
g = Graph(vertices)
print(g.get_neighbors('bob'))
g.add(Vertex("alice", ['bob', 'tom']))
print(g.get_neighbors('alice'))
