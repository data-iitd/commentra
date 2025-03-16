#include<stdio.h>

#define MAX 100005  # Maximum size of the queue
#define N 100       # Maximum size of the name string

# Define a structure to hold a person's name and their time
class P:
  def __init__(self, name, t):
    self.name = name
    self.t = t

# Declare a queue to hold P structures
Q = [P(0,0) for i in range(MAX+1)]
head, tail = 0, 0  # Head and tail pointers for the queue

# Function to add an element to the queue
def Enqueue(x):
  # Wrap around the tail if it reaches the maximum size
  if(MAX==tail): tail=0
  Q[tail] = x  # Add the element to the queue
  tail += 1     # Move the tail pointer forward

# Function to remove and return an element from the queue
def Dequeue():
  # Wrap around the head if it reaches the maximum size
  if(head==MAX): head=0
  return Q[head++]  # Return the element at the head and move the head pointer forward

n, q = map(int, input().split())  # Read the number of people and the query time

# Read each person's name and time, and enqueue them
for i in range(n):
  a = P(*input().split())  # Read name and time
  Enqueue(a)  # Add the person to the queue

# Process the queue until all people have been served
while(n!= 0):
  a = Dequeue()  # Remove the front person from the queue
  # Check if the person's time exceeds the query time
  if(a.t > q):
    a.t = a.t - q  # Reduce their time by the query time
    T = T + q      # Add query time to total time
    Enqueue(a)     # Re-enqueue the person with the remaining time
  else:
    T = T + a.t    # Add the person's time to total time
    print(a.name, T)  # Print the person's name and total time
    n -= 1  # Decrease the count of people left to serve

# 