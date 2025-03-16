
import sys

# Define a constant size for the buffered reader
size = 1000000

# Create a buffered reader with the specified size
reader = sys.stdin.buffer.read(size)

# Function to read the next line from standard input
def next_line():
  return reader.readline().decode('utf-8')

# Function to read two integers from the next line of input
def next_ints():
  return list(map(int, next_line().split()))

# Function to read an array of integers from the next line of input
def next_int_array():
  return list(map(lambda x: int(x) - 1, next_line().split()))

# Declare global variables for union-find structure
par = []
rank = []

def main():
  # Read the number of elements (n) and number of unions (m)
  n, m = next_ints()
  # Read the array of integers
  p = next_int_array()
  x, y = 0, 0
  
  # Initialize the union-find structure
  initialize(n)
  
  # Process each union operation
  for i in range(m):
    x, y = next_ints() # Read the pair of integers for union
    unite(x - 1, y - 1) # Unite the two elements (convert to zero-based index)
  
  # Count the number of elements that are in the same set as their corresponding value in p
  s = 0
  for i in range(n):
    if same(i, p[i]): # Check if the element is in the same set
      s += 1 # Increment the count
  
  # Print the result
  print(s)

# Function to initialize the union-find structure
def initialize(n):
  global par, rank
  par = [i for i in range(n)] # Create parent array
  rank = [0 for _ in range(n)] # Create rank array

# Function to find the root of the element with path compression
def root(i):
  if par[i] == i:
    return i # Return the root if it is its own parent
  par[i] = root(par[i]) # Path compression
  return par[i] # Return the root

# Function to check if two elements are in the same set
def same(i, j):
  return root(i) == root(j) # Check if their roots are the same

# Function to unite two elements into the same set
def unite(i, j):
  i = root(i) # Find the root of the first element
  j = root(j) # Find the root of the second element
  
  if i == j:
    return # If they are already in the same set, do nothing
  
  # Union by rank
  if rank[i] < rank[j]:
    par[i] = j # Make j the parent of i
  else:
    par[j] = i # Make i the parent of j
    if rank[i] == rank[j]:
      rank[i] += 1 # Increment rank if they were the same

# End of code
