
#include<stdio.h>
#include<string.h>

#define M 1046527 /* Define the size of the hash table */
#define L 14      /* Define the length of each string in the hash table */

H = [[''] * L for i in range(M)] # Declare a 2D array named H as the hash table

def getChar(ch):
  # A helper function to convert a single character into its corresponding integer value
  if ch == 'A': return 1
  elif ch == 'C': return 2
  elif ch == 'G': return 3
  elif ch == 'T': return 4
  return 0

# A function to convert a string into an integer value
def getKey(str):
  sum = 0
  p = 1
  for i in range(len(str)):
    sum += p*(getChar(str[i]))
    p *= 5
  return sum

# A helper function to calculate the first hash index
def h1(key): return key % M

# A helper function to calculate the second hash index
def h2(key): return 1 + (key % (M - 1))

# A function to check if a string is already present in the hash table
def find(str):
  i = 0
  key = getKey(str) # Calculate the key for the given string
  # Iterate through the hash table until the string is found or the hash table is exhausted
  while True:
    hash = (h1(key) + i * h2(key))%M
    if H[hash] == str: return True
    # If the current index in the hash table is empty, insert the string and return
    elif len(H[hash]) == 0: return False
    i += 1

# A function to insert a string into the hash table
def insert(str):
  i = 0
  key = getKey(str) # Calculate the key for the given string
  # Iterate through the hash table until an empty index is found
  while True:
    hash = (h1(key) + i * h2(key))%M
    if len(H[hash]) == 0:
      H[hash] = str # Copy the string into the empty index
      return
    i += 1

n = int(input()) # Read the number of operations

for i in range(n):
  com, str = input().split() # Read a command and a string

  if com == 'i':
    # If the command is 'insert', insert the string into the hash table
    insert(str)
  else:
    # If the command is 'find', check if the string is present in the hash table
    if find(str):
      print("yes")
    else:
      print("no")

# 