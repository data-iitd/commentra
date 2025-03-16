#include <stdio.h> # Step 1: Include necessary headers

def main(): # Step 2: Define the main function
  i, a, b, s = 0, 0, 0, 1 # Step 3: Declare necessary variables
  count = [0, 0, 0, 0] # Declare an array to store the count of connections for each node

  for i in range(4): count[i] = 0 # Step 4: Initialize the count array

  for i in range(3): # Step 5: Read input values and update the count array
    a, b = map(int, input().split())
    count[a-1] += 1 # Increment the count for node a
    count[b-1] += 1 # Increment the count for node b

  for i in range(4): s *= count[i] # Step 6: Calculate the product of the counts

  if s == 4: print("YES\n") # Step 7: Check if the product is 4 and print the result
  else: print("NO\n")

if __name__ == "__main__": # Step 8: Call the main function
  main()

