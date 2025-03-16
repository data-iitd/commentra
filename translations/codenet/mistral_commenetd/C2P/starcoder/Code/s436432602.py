
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// Function to run the logic of the program
def run():
  # Declare variables
  n, k = 0, 0

  # Read input values of n and k from the user
  print("Enter the number of elements in the array and the target sum: ")
  n, k = map(int, input().split())

  # Declare an array of size n to store the elements of the array
  a = [0] * n

  # Read the elements of the array from the user
  print("Enter %d integers: " % n)
  for i in range(n):
    a[i] = int(input())

  # Declare a dynamic array of size k+1 to store the dp values
  dp = [0] * (k + 1)

  # Initialize all dp values as false initially
  for i in range(k + 1):
    dp[i] = 0

  # Calculate the dp values for all sums from 1 to k
  for i in range(1, k + 1):
    win = 0

    # Check if there exists a subset of sum i in the given array a[]
    for j in range(n) and a[j] <= i:
      # If a[j] can be included in the subset, then check for the next element
      if dp[i - a[j]] == 1:
	win = 1
	break

    # Update the dp value for the current sum i
    dp[i] = win

  # Print the result based on the dp value for the target sum k
  print("The target sum %d is " % k, end="")
  if dp[k]:
    print("First\n") # Target sum is a subset of given array
  else:
    print("Second\n") # Target sum is not a subset of given array

# Main function to call the run function
if __name__ == "__main__":
  run()

  # Return 0 to indicate successful execution of the program
  return 0

