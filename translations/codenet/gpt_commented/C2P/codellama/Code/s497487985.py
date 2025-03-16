#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

def compare_int(a, b):
  return b - a # Sort in descending order

def gcd(a, b):
  if b == 0:
    return a # Base case: if b is 0, return a
  else:
    return gcd(b, a % b) # Recursive case

def lcm(a, b):
  return a * b // gcd(a, b) # LCM formula

def main():
  n = 0 # Number of participants
  k = 0 # Points required to win
  q = 0 # Number of questions
  a = [0] * 100001 # Array to store the questions
  point = [0] * 100001 # Array to track points of each participant

  # Read input values for n, k, and q
  n, k, q = map(int, input().split())

  # Initialize points for each participant to k
  for i in range(n):
    point[i] = k

  # Check if any participant has less points than k
  if q < k:
    for i in range(n):
      print("Yes")
      return

  # Process each question and update points for the corresponding participant
  for i in range(q):
    a[i] = int(input()) # Read the participant number for the question
    point[a[i] - 1] += 1 # Increment the point for the participant who answered

    # Update points for other participants
    for j in range(n):
      if a[i] != (j + 1) and point[j] < k:
        point[j] += 1

  # Determine if each participant has enough points to win
  for i in range(n):
    if k - (q - point[i]) > 0: # Check if the participant has enough points
      print("Yes") # Participant can win
    else:
      print("No") # Participant cannot win

if __name__ == "__main__":
  main()

