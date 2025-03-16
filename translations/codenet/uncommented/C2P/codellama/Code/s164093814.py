#include<stdio.h>
#include<string.h>

#define M 1046527/* your task*/
#define L 14

H = [['']*L for i in range(M)] # Hash Table

def getChar(ch):
  if ch == 'A': return 1
  elif ch == 'C': return 2
  elif ch == 'G': return 3
  elif ch == 'T': return 4
  return 0

# convert a string into an integer value
def getKey(str):
  sum = 0
  p = 1
  for i in range(len(str)):
    sum += p*(getChar(str[i]))
    p *= 5
  return sum

def h1(key): return key % M
def h2(key): return 1 + (key % (M - 1))

def find(str):
  i = 0
  while True:
    hash = (h1(key) + i * h2(key))%M
    if H[hash] == str: return 1
    elif len(H[hash]) == 0: return 0
    i += 1
  return 0

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

# your task

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

