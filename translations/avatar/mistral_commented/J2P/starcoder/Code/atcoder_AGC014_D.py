
import sys

# Declaring static variables
g = []
maxMatching = 0

# Function to find the maximum number of edges that can be matched in a bipartite graph
def maxMatching(v, p):
    a = 0 # Number of edges matched from the neighboring vertices of 'v'
    o = 0 # Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    # Iterating through all the neighbors of 'v'
    for w in g[v]:
        if w == p: continue # Skip if the neighbor is 'p' (self-loop)

        # Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        r = maxMatching(w, v)
        a += r / 2
        o += r % 2

    # Returning the result based on the parity of 'o'
    return 2 * a + min(1, o)

# Main function
if __name__ == "__main__":
    # Creating an instance of MyScanner class for reading input
    sc = MyScanner()

    # Reading the number of vertices in the graph
    n = sc.nextInt()

    # Initializing the graph as an ArrayList of ArrayLists
    g = [[] for i in range(n)]

    # Reading the edges and adding them to the graph
    for i in range(n - 1):
        a = sc.nextInt() - 1 # Reading the first vertex of the edge
        b = sc.nextInt() - 1 # Reading the second vertex of the edge
        g[a].append(b) # Adding the edge from 'a' to 'b'
        g[b].append(a) # Adding the edge from 'b' to 'a'

    # Finding the maximum number of edges that can be matched in the graph
    maxMatching = maxMatching(0, -1) / 2

    # Printing the result based on whether all vertices have even degree or not
    if 2 * maxMatching == n:
        print("Second")
    else:
        print("First")

# 