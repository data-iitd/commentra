#include<stdio.h>
#include<stdlib.h>

def run():
  # Read the number of elements (n) and the target value (k)
  n, k = map(int, input().split())
  
  # Declare an array to store the elements
  a = []
  
  # Declare loop variables
  i, j = 0, 0
  
  # Read n elements into the array a
  for i in range(n):
    a.append(int(input()))
  
  # Allocate memory for the dynamic programming array dp
  dp = [0] * (k + 1)
  
  # Iterate from 1 to k to fill the dp array
  for i in range(1, k + 1):
    # Initialize the win flag to 0
    win = 0
    
    # Check each element in the array a to see if it can be subtracted from i
    for j in range(n):
      if dp[i - a[j]] == 0:
        # If the resulting value is zero, set win to 1
        win = 1
    
    # Set dp[i] to the win flag
    dp[i] = win
  
  # Print the result based on the value of dp[k]
  print("First" if dp[k] else "Second")

if __name__ == "__main__":
  # Call the run function to execute the game strategy
  run()

