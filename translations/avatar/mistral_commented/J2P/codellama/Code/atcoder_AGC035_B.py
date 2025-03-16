
import sys

# Importing the utility class Scanner for reading input from the standard input stream.

class Main:

    # Main method where the program starts execution.
    def main(self):
        sc = sys.stdin
        numNode = int(sc.readline())
        numEdge = int(sc.readline())

        # Initializing the connect array to store the list of neighbors for each node.
        connect = [[] for i in range(numNode)]

        # Reading the edges and adding them to the connect array.
        for i in range(numEdge):
            a, b = map(int, sc.readline().split())
            connect[a - 1].append(b - 1)
            connect[b - 1].append(a - 1)

        # Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
        if numEdge % 2 != 0:
            print(-1)
            return

        # Initializing the visited, odd, and print arrays and objects.
        visited = [0] * numNode
        odd = [False] * numNode
        print = ""

        # Calling the dfs method with the first node and -1 as the parent node.
        self.dfs(0, -1)

        # Printing the output.
        print(print)

    # Recursive depth-first search method to perform bipartite traversal.
    def dfs(self, crt, parent):
        # Marking the current node as visited.
        visited[crt] = 1

        # Iterating through the neighbors of the current node.
        crtConnect = connect[crt]
        for child in crtConnect:
            # Skipping the neighbor if it is the parent node or already visited.
            if child == parent or visited[child] == 1:
                continue

            # If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
            # Otherwise, we swap the components and continue the traversal.
            if visited[child] == 2:
                print += str(crt + 1) + " " + str(child + 1) + "\n"
                odd[crt] = not odd[crt]
            else:
                self.dfs(child, crt)
                if odd[child]:
                    print += str(child + 1) + " " + str(crt + 1) + "\n"
                    odd[child] = not odd[child]
                else:
                    print += str(crt + 1) + " " + str(child + 1) + "\n"
                    odd[crt] = not odd[crt]

        # Marking the current node as visited with component 2.
        visited[crt] = 2

# Creating an object of the Main class and calling the main method.
if __name__ == "__main__":
    main = Main()
    main.main()

