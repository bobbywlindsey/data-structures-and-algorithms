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


    def dfs(self, node_name, discovered=[]):
        discovered.append(node_name)
        neighbors = self.get_neighbors(node_name)
        for neighbor in neighbors:
            if neighbor not in discovered:
                self.dfs(neighbor, discovered)


vertices = [Vertex('bob', ['alice', 'george']),
            Vertex('george', [])]
g = Graph(vertices)
print(g.get_neighbors('bob'))
g.add(Vertex('alice', ['bob', 'tom']))
g.add(Vertex('tom', ['bob']))
print(g.get_neighbors('alice'))
g.dfs('alice')

