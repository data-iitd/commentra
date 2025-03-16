import sys

INF = 1000000001

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def main():
    V, E, r = map(int, sys.stdin.readline().split())
    edges = []

    for _ in range(E):
        source, target, weight = map(int, sys.stdin.readline().split())
        edges.append(Edge(source, target, weight))

    distances = [INF] * V
    distances[r] = 0
    prev_distances = [0] * V

    for _ in range(V - 1):
        for j in range(V):
            prev_distances[j] = distances[j]

        for edge in edges:
            distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

        if all(distances[i] == prev_distances[i] for i in range(V)):
            break

    for distance in distances:
        if distance == INF:
            print("INF")
        else:
            print(distance)

if __name__ == "__main__":
    main()
