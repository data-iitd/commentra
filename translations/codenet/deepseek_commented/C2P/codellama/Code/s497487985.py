#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

def compare_int(a, b):
  return b - a # 大きい順

def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a % b)

def lcm(a, b):
  return a * b // gcd(a, b)

def main():
  n = 0 # Number of players
  k = 0 # Initial points
  q = 0 # Number of queries
  a = [0] * 100001 # Array to store query results
  point = [0] * 100001 # Array to store points for each player

  # Read input values
  n, k, q = map(int, input().split())

  # Process each query to update points
  for i in range(q):
    a[i] = int(input())
    point[a[i] - 1] += 1 # Update points for the player who answered the query

  # Determine if each player can reach the required points
  for i in range(n):
    if k - (q - point[i]) > 0:
      print("Yes") # Player can reach the required points
    else:
      print("No") # Player cannot reach the required points

if __name__ == "__main__":
  main()

