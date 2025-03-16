#include<stdio.h>
#include<string.h>

#define M 1046527 /* Size of the hash table */
#define L 14      /* Maximum length of strings to be stored in the hash table */

H = [[''] * L for i in range(M)] # Hash Table to store strings

# Function to convert a character to a corresponding integer value
def getChar(ch):
  if ch == 'A': return 1 # A maps to 1
  elif ch == 'C': return 2 # C maps to 2
  elif ch == 'G': return 3 # G maps to 3
  elif ch == 'T': return 4 # T maps to 4
  return 0 # Return 0 for any other character

# Convert a string into a unique integer key using a polynomial rolling hash
def getKey(str):
  sum = 0
  p = 1
  for i in range(len(str)):
    sum += p * (getChar(str[i])) # Update sum with the character's value
    p *= 5 # Increase power of 5 for the next character
  return sum # Return the computed key

# Hash function h1: Computes the primary hash index
def h1(key):
  return key % M

# Hash function h2: Computes the secondary hash index for collision resolution
def h2(key):
  return 1 + (key % (M - 1))

# Function to find a string in the hash table
def find(str):
  key = getKey(str) # Get the key for the string
  i = 0 # Initialize index for probing
  while True:
    # Compute the hash index using double hashing
    hash = (h1(key) + i * h2(key)) % M
    if H[hash] == str: return 1 # String found
    elif len(H[hash]) == 0: return 0 # Empty slot indicates string not found
    i += 1 # Increment index for next probe
  return 0 # Should not reach here

# Function to insert a string into the hash table
def insert(str):
  key = getKey(str) # Get the key for the string
  i = 0 # Initialize index for probing
  while True:
    # Compute the hash index using double hashing
    hash = (h1(key) + i * h2(key)) % M
    if H[hash] == str: return 1 # String already exists
    elif len(H[hash]) == 0: # If the slot is empty
      H[hash] = str # Insert the string
      return 0 # Insertion successful
    i += 1 # Increment index for next probe
  return 0 # Should not reach here

# Read the number of commands
n = int(input())

# Process each command
for i in range(n):
  com, str = input().split() # Read command and string

  # Check if the command is to insert a string
  if com[0] == 'i':
    insert(str) # Insert the string into the hash table
  else:
    # If the command is not insert, check if the string exists
    if find(str):
      print("yes") # String found
    else:
      print("no") # String not found

# 