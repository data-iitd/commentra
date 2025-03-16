
import sys

# Constant representing a blank color
BLANK_COLOR = -1

# Private function to check if a color is blank (unassigned)
def isBlank(color):
    return color == BLANK_COLOR

# Private function to initialize the colors array with blank colors
def initializeColors(numberOfVertices):
    colors = [BLANK_COLOR] * numberOfVertices
    return colors

# Private function to get the vertices sorted by their degree in descending order
def getSortedNodes(graph):
    return sorted(range(len(graph)), key=lambda v: -len(graph[v]))

# Private function to compute which colors are used by adjacent vertices
def computeUsedColors(graph, vertex, colors):
    usedColors = [False] * len(graph)
    
    # Check the colors of all adjacent vertices
    for neighbor in graph[vertex]:
        if not isBlank(colors[neighbor]):
            usedColors[colors[neighbor]] = True
    
    return usedColors

# Private function to find the first unused color
def firstUnusedColor(usedColors):
    return next((color for color in range(len(usedColors)) if not usedColors[color]), -1)

# Main function to find a valid coloring for the graph
def findColoring(graph):
    # Initialize colors for all vertices to blank
    colors = initializeColors(len(graph))
    
    # Get the vertices sorted by their degree in descending order
    sortedVertices = getSortedNodes(graph)
    
    # Assign colors to each vertex
    for vertex in sortedVertices:
        # If the vertex is uncolored, proceed to color it
        if isBlank(colors[vertex]):
            # Determine which colors are already used by adjacent vertices
            usedColors = computeUsedColors(graph, vertex, colors)
            
            # Find the first unused color
            newColor = firstUnusedColor(usedColors)
            
            # Assign the new color to the vertex
            colors[vertex] = newColor
    
    return colors # Return the array of colors assigned to vertices

# Read the number of vertices and edges from input
vertices, edges = map(int, input().split())

# Initialize the graph with the specified number of vertices
graph = [[] for _ in range(vertices)]

# Read each edge and add it to the graph
for _ in range(edges):
    fromVertex, toVertex = map(int, input().split())
    graph[fromVertex].append(toVertex)
    graph[toVertex].append(fromVertex)

# Find the coloring of the graph
colors = findColoring(graph)

# Output the colors assigned to each vertex
print("Vertex Colors:")
for vertex in range(vertices):
    print(f"Vertex {vertex}: Color {colors[vertex]}")

# End of code
print("