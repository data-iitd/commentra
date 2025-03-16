import sys

INF = 1000000001
N = 100000

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

edges = []

distances = [INF] * N
prev_distances = [0] * N

def main():
    V, E, r = map(int, input().split())

    for _ in range(E):
        source, target, distance = map(int, input().split())
        new_edge = Edge(source, target, distance)
        edges.append(new_edge)

    # Initialize distances array
    distances[r] = 0

    for _ in range(1, V):
        for j in range(V):
            prev_distances[j] = distances[j]

        for edge in edges:
            distances[edge.target] = min(distances[edge.source] + edge.weight, distances[edge.target])

        same = True
        for j in range(V):
            if distances[j] != prev_distances[j]:
                same = False
                break

        if same:
            break

    for i in range(V):
        if distances[i] == INF:
            print("INF")
        else:
            print(distances[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
