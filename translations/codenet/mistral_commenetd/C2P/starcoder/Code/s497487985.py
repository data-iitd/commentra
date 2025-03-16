#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))

# Function to compare two integers in descending order
def compare_int(a, b):
  return b - a # 大きい順

# Function to find the greatest common divisor (GCD) of two integers
def gcd(a, b):
  if(b == 0):
    # If 'b' is 0, then 'a' is the GCD
    return a
  else:
    # Otherwise, recursively call the function with 'b' and the remainder of 'a' divided by 'b'
    return gcd(b, a % b)

# Function to find the least common multiple (LCM) of two integers
def lcm(a, b):
  # The LCM is the product of the two numbers divided by their GCD
  return a * b / gcd(a, b)

# Main function
def main():
  n = int(input()) # Number of people
  k = int(input()) # Total points
  q = int(input()) # Number of queries
  a = [0] * q # Array to store the query numbers
  point = [0] * n # Array to store the current points for each person

  # Read input values
  # scanf("%ld%lld%ld", &n, &k, &q);

  # Initialize the points for all people to 'k'
  for i in range(n):
    point[i] = k

  # Check if it's possible to distribute the points to all queries
  if(q < k):
    # If the total number of queries is less than the total points, then it's impossible to distribute the points to all queries
    for i in range(n):
      print("Yes") # This will never be reached
      return 0

  # Distribute the points to each query one by one
  for i in range(q):
    a[i] = int(input()) # Read the query number
    point[a[i] - 1] += 1 # Increase the points for the person with the query number

    # Try to distribute the points to other people if the current person doesn't get the point
    for j in range(n):
      if(a[i]!= (j + 1) and point[j] < k): # If the current person's number is different from 'j + 1' and the points for person 'j' are less than 'k'
	point[j] += 1 # Increase the points for person 'j'
  # Check if it's possible to distribute the remaining points to the remaining people
  for i in range(n):
    if(k - (q - point[i]) > 0): # If the remaining points are greater than the difference between the total points and the points already distributed
      print("Yes") # It's possible to distribute the remaining points to the remaining people
    else:
      print("No") # It's impossible to distribute the remaining points to the remaining people
  return 0

# 