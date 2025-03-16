
#include<stdio.h>
#include<string.h>

#define LEN 100005

// Define a structure to hold the name and time of each process
class pp:
  def __init__(self):
    self.name = ""
    self.t = 0

# Declare a queue to hold the processes
Q = [pp() for i in range(LEN)]
head = 0
tail = 0
n = 0

# Function to add a process to the queue
def enqueue(x):
  Q[tail] = x
  tail = (tail + 1) % LEN

# Function to remove a process from the queue
def dequeue():
  x = Q[head]
  head = (head + 1) % LEN
  return x

# Function to find the minimum of two integers
def min(a, b):
  return a if a < b else b

def main():
  elaps = 0
  c = 0
  i = 0
  q = 0
  u = pp()

  # Read the number of processes and the time quantum
  scanf("%d %d", &n, &q)

  # Read the process names and their respective times
  for(i = 1 ; i <= n ; i++){
    scanf("%s", Q[i].name)
    scanf("%d", &Q[i].t)
  }

  # Initialize head and tail pointers for the queue
  head = 1
  tail = n + 1

  # Process the queue until all processes are completed
  while(head!= tail):
    u = dequeue()
    c = min(q, u.t)
    u.t -= c
    elaps += c
    if(u.t > 0):
      enqueue(u)
    else:
      printf("%s %d\n", u.name, elaps)

  return 0

# 