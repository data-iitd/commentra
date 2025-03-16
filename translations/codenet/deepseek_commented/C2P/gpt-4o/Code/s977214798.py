# Header Files and Preprocessor Directives
import sys
from collections import defaultdict

# Input Function
def nextint():
    return int(sys.stdin.readline().strip())

# Global Variables
n = 0
a = []
e1 = defaultdict(int)
e2 = defaultdict(int)
d = defaultdict(int)
b = defaultdict(bool)

# Function Definitions
def p(a, b):
    if a < b:
        return a + b * n
    else:
        return b + a * n

def f(from_node):
    if b[from_node]: 
        return -1  # If node is already visited, return -1 indicating a cycle
    if from_node in d: 
        return d[from_node]  # If distance is already calculated, return it
    b[from_node] = True  # Mark the node as visited
    max_length = 0

    to = e1[from_node]
    if to != 0:
        now = f(to)  # Recursively find the longest path from 'to'
        if now < 0: 
            return now  # If there's a cycle, return -1
        if now > max_length: 
            max_length = now  # Update max if a longer path is found

    to = e2[from_node]
    if to != 0:
        now = f(to)  # Recursively find the longest path from 'to'
        if now < 0: 
            return now  # If there's a cycle, return -1
        if now > max_length: 
            max_length = now  # Update max if a longer path is found

    b[from_node] = False  # Unmark the node as visited (backtracking)
    d[from_node] = max_length + 1  # Store and return the longest path length
    return d[from_node]

# Main Function
if __name__ == "__main__":
    n = nextint()  # Read the size of the problem
    a = [list(map(lambda x: int(x) - 1, sys.stdin.readline().strip().split())) for _ in range(n)]  # Read and adjust indices to be 0-based

    for i in range(n):
        for j in range(n - 1):
            from_node = p(i, a[i][j])  # Create a unique node index 'from'
            to_node = p(i, a[i][j + 1])  # Create a unique node index 'to'
            if e1[from_node] == 0:
                e1[from_node] = to_node  # Assign 'to' to e1 of 'from'
            elif e2[from_node] == 0:
                e2[from_node] = to_node  # Assign 'to' to e2 of 'from'
            else:
                print(-1)  # If both e1 and e2 are already assigned, print -1 and exit
                sys.exit(0)

    ans = 0
    for i in range(n):
        from_node = p(i, a[i][0])  # Create a unique starting node index 'from'
        now = f(from_node)  # Find the longest path from 'from'
        if now < 0:
            ans = -1  # If there's a cycle, set ans to -1
            break
        if now > ans: 
            ans = now  # Update ans if a longer path is found

    print(ans)  # Print the result
# <END-OF-CODE>
