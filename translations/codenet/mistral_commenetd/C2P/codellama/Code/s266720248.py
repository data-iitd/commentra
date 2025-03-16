#include<stdio.h>
#include<string.h>

#define LEN 100005 // Maximum size of the queue

# Define a structure 'pp' to store name and time of each process
class P:
  def __init__(self, name, t):
    self.name = name
    self.t = t

# Initialize head and tail pointers and size of the queue
Q = [P("", 0) for i in range(LEN)]
head, tail, n = 0, 1, 0

# Function to add an element to the queue
def enqueue(x):
  Q[tail] = x # Add the process to the queue
  tail = (tail + 1) % LEN # Increment tail pointer

# Function to remove an element from the queue
def dequeue():
  x = Q[head] # Store the process to be removed
  head = (head + 1) % LEN # Increment head pointer
  return x # Return the removed process

# Function to find the minimum of two integers
def min(a, b):
  return a if a < b else b # Return the smaller integer

def main():
  elaps = 0 # Initialize elapsed time and control variable c
  c = 0
  i, q = 0, 0 # Loop counter and number of processes to be served

  # Read number of processes and number of queries
  n, q = map(int, input().split())

  # Allocate memory for each process and read its name and time
  for i in range(n):
    name = input() # Read name of the process
    t = int(input()) # Read time taken by the process
    enqueue(P(name, t)) # Add the process to the queue

  head = 1
  tail = n + 1 # Initialize head and tail pointers

  # Simulate the queue and serve processes based on their arrival time and time taken
  while head != tail:
    u = dequeue() # Dequeue a process
    c = min(q, u.t) # Find the minimum of remaining queries and time taken by the process
    u.t -= c # Subtract the time taken to serve the queries
    elaps += c # Add the time taken to serve the queries to elapsed time
    if u.t > 0: enqueue(u) # If the process still has time left, add it back to the queue
    else:
      print(u.name, elaps) # Print the name of the process and elapsed time when it is finished

if __name__ == "__main__":
  main()

