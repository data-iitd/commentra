import sys

# Function to read the next line from standard input
def next_line():
    return sys.stdin.readline().strip()

# Function to read two integers from the next line of input
def next_ints():
    return map(int, next_line().split())

# Function to read an array of integers from the next line of input
def next_int_array():
    return list(map(int, next_line().split()))

# Declare global variables for union-find structure
par = []
rank = []

def initialize(n):
    global par, rank
    par = list(range(n))  # Create parent array
    rank = [0] * n        # Create rank array

def root(i):
    if par[i] == i:
        return i  # Return the root if it is its own parent
    par[i] = root(par[i])  # Path compression
    return par[i]  # Return the root

def same(i, j):
    return root(i) == root(j)  # Check if their roots are the same

def unite(i, j):
    i = root(i)  # Find the root of the first element
    j = root(j)  # Find the root of the second element
    
    if i == j:
        return  # If they are already in the same set, do nothing
    
    # Union by rank
    if rank[i] < rank[j]:
        par[i] = j  # Make j the parent of i
    else:
        par[j] = i  # Make i the parent of j
        if rank[i] == rank[j]:
            rank[i] += 1  # Increment rank if they were the same

def main():
    n, m = next_ints()  # Read the number of elements (n) and number of unions (m)
    p = next_int_array()  # Read the array of integers
    initialize(n)  # Initialize the union-find structure
    
    # Process each union operation
    for _ in range(m):
        x, y = next_ints()  # Read the pair of integers for union
        unite(x - 1, y - 1)  # Unite the two elements (convert to zero-based index)
    
    # Count the number of elements that are in the same set as their corresponding value in p
    s = sum(1 for i in range(n) if same(i, p[i] - 1))  # Check if the element is in the same set
    
    # Print the result
    print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
