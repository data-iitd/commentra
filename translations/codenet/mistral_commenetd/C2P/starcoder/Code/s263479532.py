
#include<stdio.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

def prim(): # Function to implement Prim's Algorithm

n = int(input()) # Read the number of vertices from the user
G = [[0 for i in range(n)] for j in range(n)] # Initialize the 2D array G with input values

for i in range(n):
  for j in range(n):
    G[i][j] = int(input())

print(prim()) # Call the prim function and print the result

def prim(): # Function to implement Prim's Algorithm

n = int(input()) # Read the number of vertices from the user
G = [[0 for i in range(n)] for j in range(n)] # Initialize the 2D array G with input values

for i in range(n):
  for j in range(n):
    G[i][j] = int(input())

print(prim()) # Call the prim function and print the result

if __name__ == "__main__":
  prim()

