#include<stdio.h>
#include<string.h>

#define M 1046527 /* Size of the hash table */
#define L 14      /* Maximum length of strings */

H = [[''] * L for i in range(M)] # Hash Table

# Convert a character to an integer value
def getChar(ch):
  if ch == 'A': return 1
  elif ch == 'C': return 2
  elif ch == 'G': return 3
  elif ch == 'T': return 4
  return 0

# Convert a string into an integer value
def getKey(str):
  sum = 0
  p = 1
  for i in range(len(str)):
    sum += p*(getChar(str[i]))
    p *= 5
  return sum

# First hash function
def h1(key): return key % M

# Second hash function
def h2(key): return 1 + (key % (M - 1))

# Search for a string in the hash table
def find(str):
  i = 0
  while True:
    hash = (h1(key) + i * h2(key))%M
    if H[hash] == str: return 1
    elif len(H[hash]) == 0: return 0
    i += 1
  return 0

# Insert a string into the hash table
def insert(str):
  i = 0
  while True:
    hash = (h1(key) + i * h2(key))%M
    if H[hash] == str: return 1
    elif len(H[hash]) == 0:
      H[hash] = str
      return 0
    i += 1
  return 0

# Main function to handle commands
def main():
  n = int(input())

  for i in range(n):
    com, str = input().split()

    if com[0] == 'i':
      insert(str)
    else:
      if find(str):
        print("yes")
      else:
        print("no")

if __name__ == "__main__":
  main()

