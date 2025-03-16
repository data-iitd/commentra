#include<stdio.h> # Include the standard input/output library for input/output functions

#define MAX 100005 # Define the maximum number of processes
#define N 100 # Define the maximum length of the process name

class P: # Define a class for processes
  def __init__(self, name, t): # Initialize the process name and time
    self.name = name
    self.t = t

Q = [P("", 0) for i in range(MAX+1)] # Declare a queue of processes
head = 0 # Initialize pointers for the queue
tail = 0

def Enqueue(x): # Function to add a process to the queue
  global tail # Declare the global variable tail
  if tail == MAX: # Wrap around if tail reaches the maximum size
    tail = 0
  Q[tail] = x # Assign the process to the queue
  tail += 1 # Increment the tail pointer

def Dequeue(): # Function to remove and return the process at the front of the queue
  global head # Declare the global variable head
  if head == MAX: # Wrap around if head reaches the maximum size
    head = 0
  return Q[head++] # Return the process and increment the head pointer

def main(): # Main function to execute the process scheduling
  n, q = map(int, input().split()) # Read the number of processes and the quantum
  T = 0 # Declare variables for iteration, quantum, number of processes, and total time
  a = P("", 0) # Declare a process variable

  for i in range(n): # Loop to read each process
    a.name, a.t = input().split() # Read the process name and time
    Enqueue(a) # Enqueue the process

  while n != 0: # Loop to process each process
    a = Dequeue() # Dequeue a process
    if a.t > q: # If the process time is greater than the quantum
      a.t = a.t - q # Reduce the process time by the quantum
      T += q # Increment the total time by the quantum
      Enqueue(a) # Enqueue the process again
    else: # If the process time is less than or equal to the quantum
      T += a.t # Increment the total time by the process time
      print(a.name, T) # Print the process name and total time
      n -= 1 # Decrement the number of processes

  return 0 # Return 0 to indicate successful execution


