

# Python code to translate the given C code

# Define a class for a node
class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None

# Initialize the linked list
def init():
  global N
  N = Node(0) # Create a node with a key value of 0
  N.next = N
  N.prev = N

# Print the contents of the linked list
def printList():
  cur = N.next
  snl = 1
  while cur!= N:
    if snl == 0:
      print(" ", end="")
    print(cur.key, end="")
    cur = cur.next
    snl = 0
  print()

# Delete the first node from the list
def deleteFirst():
  global N
  t = N.next
  N.next = t.next
  t.next.prev = N

# Delete the last node from the list
def deleteLast():
  global N
  delnode = N.prev
  N.prev = delnode.prev
  delnode.prev.next = N
  del delnode

# Delete a node with the given key from the list
def delete(skey):
  judge = 0
  n = N.next
  while n!= N:
    if n.key == skey:
      judge = 1
      break
    n = n.next
  if judge == 1:
    n = N.next
    t = n.prev
    t.next = n.next
    t.next.prev = t
    del n

# Insert a new node with the given key into the list
def insert(skey):
  global N
  new = Node(skey)
  if N.next == N:
    new.next = N
    N.next = new
    new.prev = N
    N.prev = new
  else:
    new.next = N.next
    N.next.prev = new
    N.next = new
    new.prev = N

# Main function to read commands and perform the corresponding operations
def main():
  n = int(input())
  init()
  for i in range(n):
    com = input().split()
    if com[0] == "insert":
      insert(int(com[1]))
    elif com[0] == "deleteFirst":
      deleteFirst()
    elif com[0] == "deleteLast":
      deleteLast()
    else:
      delete(int(com[1]))
  printList()

if __name__ == "__main__":
  main()

