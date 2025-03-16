# Importing necessary libraries
import sys
from collections import defaultdict

# Main function starts here
def main():
    # Read the number of vertices from the input
    n = int(sys.stdin.readline().strip())

    # Initialize an answer list of size n
    ans = [0] * n

    # Read the edges and increment the count of each vertex in the answer list
    for _ in range(n - 1):
        a = int(sys.stdin.readline().strip())
        a -= 1  # Decrement the vertex index as it is 0-indexed
        ans[a] += 1  # Increment the count of the vertex

    # Print the answer list
    for count in ans:
        print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
