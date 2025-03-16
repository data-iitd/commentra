#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000000000

// Define a structure for a doubly linked list node
class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None

# Function to initialize the doubly linked list
def init():
  global N
  N = Node(0)
  N.next = N
  N.prev = N

# Function to print the elements of the list
def printList():
  cur = N.next
  snl = 1
  while(cur!= N):
    if ( snl == 0)  print(" ", end="")
    print(cur.key, end="")
    cur = cur.next
    snl = 0
  print("\n")

# Function to delete the first node in the list
def deleteFirst():
  t = N.next
  N.next = t.next
  t.next.prev = N
  del t

# Function to delete the last node in the list
def deleteLast():
  delnode = N.prev
  N.prev = delnode.prev
  delnode.prev.next = N
  del delnode

# Function to delete a node with a specific key
def delete(skey):
  judge = 0
  n = N.next
  while(n!= N):
    if(n.key == skey):
      judge = 1
      break
    n=n.next
  if(judge == 1):
    t = n.prev
    t.next = n.next
    t.next.prev = t
    del n

# Function to insert a new node with a specific key
def insert(skey):
  global N
  new = Node(skey)
  if(N.next == N):
    new.next = N
    N.next = new
    new.prev = N
    N.prev = new
  else:
    new.next = N.next
    N.next.prev = new
    N.next = new
    new.prev = N
  del new

# Main function to execute the program
def main():
  n = int(input())
  init()
  for i in range(n):
    com = input()
    if(com == "insert"):
      key = int(input())
      insert(key)
    elif(com == "deleteFirst"):
      deleteFirst()
    elif(com == "deleteLast"):
      deleteLast()
    else:
      key = int(input())
      delete(key)
  printList()

main()

