
# Python code to simulate the queue

# Define a class 'Process' to store name and time of each process
class Process:
  def __init__(self, name, t):
    self.name = name
    self.t = t

# Initialize head and tail pointers and size of the queue
Q = []
head = 0
tail = 0
n = 0

# Function to add an element to the queue
def enqueue(x):
  global Q, tail
  Q.append(x) # Add the process to the queue
  tail += 1 # Increment tail pointer

# Function to remove an element from the queue
def dequeue():
  global Q, head
  x = Q[head] # Store the process to be removed
  head += 1 # Increment head pointer
  return x # Return the removed process

# Function to find the minimum of two integers
def min(a, b):
  return a if a < b else b # Return the smaller integer

# Read number of processes and number of queries
n, q = map(int, input().split())

# Allocate memory for each process and read its name and time
for i in range(1, n + 1):
  name = input() # Read name of the process
  t = int(input()) # Read time taken by the process
  enqueue(Process(name, t)) # Add the process to the queue

# Simulate the queue and serve processes based on their arrival time and time taken
elaps = 0 # Initialize elapsed time
while head < tail:
  u = dequeue() # Dequeue a process
  c = min(q, u.t) # Find the minimum of remaining queries and time taken by the process
  u.t -= c # Subtract the time taken to serve the queries
  elaps += c # Add the time taken to serve the queries to elapsed time
  if u.t > 0: enqueue(u) # If the process still has time left, add it back to the queue
  else:
    print(u.name, elaps) # Print the name of the process and elapsed time when it is finished

# End of code

