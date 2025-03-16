# Define a constant size for the buffered reader
size = 1000000

# Create a buffered reader with the specified size
reader = sys.stdin

# Function to read the next line from standard input
def NextLine():
  line = reader.readline()
  if not line:
    raise EOFError
  return line

# Function to read two integers from the next line of input
def NextInts():
  # Split the line into strings and convert to integers
  s = NextLine().split()
  x = int(s[0]) # Convert the first string to an integer
  y = int(s[1]) # Convert the second string to an integer
  return x, y # Return the two integers

# Function to read an array of integers from the next line of input
def NextIntArray():
  # Split the line into strings
  s = NextLine().split()
  # Create an integer slice of the same length as the string slice
  a = [0] * len(s)
  
  # Convert each string to an integer and decrement by 1 for zero-based indexing
  for i in range(len(s)):
    a[i] = int(s[i]) - 1
  
  return a # Return the integer array

# Declare global variables for union-find structure
par = []
rank = []

def main():
  # Read the number of elements (n) and number of unions (m)
  n, m = NextInts()
  # Read the array of integers
  p = NextIntArray()
  x, y = 0, 0
  
  # Initialize the union-find structure
  initialize(n)
  
  # Process each union operation
  for i in range(m):
    x, y = NextInts() # Read the pair of integers for union
    unite(x-1, y-1)   # Unite the two elements (convert to zero-based index)
  
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
  rank = [0] * n # Create rank array
  
  # Set each element's parent to itself
  for i in range(n):
    par[i] = i

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

