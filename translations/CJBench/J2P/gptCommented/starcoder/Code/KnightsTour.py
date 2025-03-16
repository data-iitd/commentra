import sys

# Class to represent a node in the graph
class Node:
    # Constructor to initialize the node
    def __init__(self, row, col, count):
        self.row = row
        self.col = col
        self.count = count

# Class to represent a graph
class Graph:
    # Constructor to initialize the graph
    def __init__(self, size):
        self.size = size
        self.nodes = []
        self.visited = [[False for i in range(size)] for j in range(size)]
        self.neighbors = [[[] for i in range(size)] for j in range(size)]
        self.total = size * size

    # Method to reset the graph with a given size
    def reset(self, size):
        self.size = size
        self.nodes = []
        self.visited = [[False for i in range(size)] for j in range(size)]
        self.neighbors = [[[] for i in range(size)] for j in range(size)]
        self.total = size * size

    # Method to add a node to the graph
    def addNode(self, row, col, count):
        self.nodes.append(Node(row, col, count))

    # Method to add a neighbor to the graph
    def addNeighbor(self, row, col, count):
        self.neighbors[row][col].append(Node(row, col, count))

    # Method to check if a node is a valid neighbor
    def isValid(self, row, col):
        return row >= 0 and row < self.size and col >= 0 and col < self.size

    # Method to check if a node is an orphan
    def isOrphan(self, count, row, col):
        if count < self.total - 1:
            for nb in self.neighbors[row][col]:
                if nb.count == 0:
                    return True
        return False

    # Recursive method to solve the knight's tour problem
    def solve(self, row, col, count):
        # If all squares are covered, return true
        if count > self.total:
            return True

        # Get the list of valid neighboring moves
        neighbor = self.neighbors[row][col]
        # If no neighbors and not all squares are covered, return false
        if len(neighbor) == 0 and count!= self.total:
            return False

        # Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
        neighbor.sort(key = lambda x: x.count)

        # Try each neighbor
        for nb in neighbor:
            nextRow = nb.row
            nextCol = nb.col
            self.visited[nextRow][nextCol] = True # Mark the square as visited

            # Check for orphan condition and recursively solve for the next move
            if not self.isOrphan(count, nextRow, nextCol) and self.solve(nextRow, nextCol, count + 1):
                return True # If solution found, return true

            # Backtrack: unmark the square
            self.visited[nextRow][nextCol] = False
        return False # No solution found

    # Method to print the solution of the knight's tour
    def printSolution(self):
        for r in range(self.size):
            for c in range(self.size):
                print(self.nodes[self.visited[r][c]].count, end = " ")
            print() # New line after each row

    # Main method to execute the knight's tour algorithm
    def main(self):
        # Read the size of the board and starting position from user input
        self.reset(int(input()))
        startRow, startCol = map(int, input().split())

        # Mark the starting position
        self.visited[startRow][startCol] = True
        self.addNode(startRow, startCol, 1)

        # Attempt to solve the knight's tour and print the result
        if self.solve(startRow, startCol, 2):
            print("Knight's tour solution:")
            self.printSolution()
        else:
            print("No solution exists.") # No solution found

# Main method to execute the program
if __name__ == "__main__":
    graph = Graph(0)
    graph.main()

