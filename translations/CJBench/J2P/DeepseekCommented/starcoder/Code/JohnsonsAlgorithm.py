# Read the number of vertices in the graph
vertices = int(input())
# Initialize the graph as a 2D array with dimensions [vertices][vertices]
graph = [[0 for i in range(vertices)] for j in range(vertices)]
# Fill the graph with values read from the input, treating "INF" as infinity
for i in range(vertices):
    for j in range(vertices):
        value = input()
        graph[i][j] = value if value!= "INF" else INF

