
import sys
sys.setrecursionlimit(10**6)
def floyd_warshall(adjacency_matrix, number_of_vertices):
    distance_matrix = [[float('inf') for _ in range(number_of_vertices)] for _ in range(number_of_vertices)]
    for source in range(number_of_vertices):
        for destination in range(number_of_vertices):
            distance_matrix[source][destination] = adjacency_matrix[source][destination]
    for intermediate in range(number_of_vertices):
        for source in range(number_of_vertices):
            for destination in range(number_of_vertices):
                if distance_matrix[source][intermediate] + distance_matrix[intermediate][destination] < distance_matrix[source][destination]:
                    distance_matrix[source][destination] = distance_matrix[source][intermediate] + distance_matrix[intermediate][destination]
    return distance_matrix
def print_distance_matrix(distance_matrix):
    for source in range(len(distance_matrix)):
        for destination in range(len(distance_matrix[0])):
            if distance_matrix[source][destination] == float('inf'):
                print("INF", end="\t")
            else:
                print(distance_matrix[source][destination], end="\t")
        print()
if __name__ == "__main__":
    number_of_vertices = int(input())
    adjacency_matrix = []
    for _ in range(number_of_vertices):
        adjacency_matrix.append(list(map(int, input().split())))
    distance_matrix = floyd_warshall(adjacency_matrix, number_of_vertices)
    print("Shortest path matrix:")
    print_distance_matrix(distance_matrix)
