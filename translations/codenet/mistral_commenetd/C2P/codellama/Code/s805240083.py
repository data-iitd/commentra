#include<stdio.h>
#define MAX 100005
#define N 100

class P:
  def __init__(self, name, t):
    self.name = name
    self.t = t

Q = [P("", 0) for i in range(MAX+1)] # Circular queue to store the processes
head, tail = 0, 0 # pointers for head and tail of the queue

def Enqueue(x):
  # Function to add a process to the queue
  if(MAX==tail): # Check if the queue is full
    tail=0
  Q[tail]=x # Store the process in the queue
  tail+=1 # Increment the tail pointer

def Dequeue():
  # Function to remove a process from the queue
  temp = P("", 0) # Temporary variable to store the process to be removed
  if(head==MAX): # Check if the queue is empty
    head=0
  temp=Q[head] # Store the process to be removed
  head+=1 # Increment the head pointer
  return temp # Return the process

n, q = map(int, input().split()) # Read the number of processes and the time limit from the input

for i in range(n): # Loop to read the details of each process and enqueue it
  name, t = input().split()
  a = P(name, int(t))
  Enqueue(a)

while(n!=0): # While there are still processes in the queue
  a = Dequeue() # Dequeue the current process
  if(a.t>q): # If the process takes more time than the limit
    a.t = a.t-q # Subtract the excess time from the process time
    T = q # Add the time limit to the total time
    Enqueue(a) # Re-enqueue the process
  else: # If the process takes less time than the limit
    T = T+a.t # Add the process time to the total time
    print(a.name, T) # Print the name and total time taken for the process
    n-=1 # Decrement the number of processes left

print("