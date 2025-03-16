#include<stdio.h> # Include the standard input/output library
int main(): # Start of the main function
  n = int(input()) # Read an integer value from the standard input and store it in 'n'
  l = [0] * 2001 # Declare an integer array 'l' of size 2001
  for i in range(n): # Iterate through all elements of the array 'l'
    l[i] = int(input()) # Read an integer value from the standard input and store it in the current index of 'l'
  for i in range(n-1): # Iterate through all elements except the last one in the array 'l'
    for j in range(i+1, n): # Iterate through the remaining elements
      if l[j] < l[i]: # If the current element is smaller than the previous one
        tmp = l[i] # Swap the current and previous elements
        l[i] = l[j]
        l[j] = tmp # Update the array 'l' with the swapped elements
  for i in range(n-2): # Iterate through all elements except the last two in the array 'l'
    for j in range(i+1, n-1): # Iterate through the remaining elements except the last one
      for k in range(j+1, n): # Iterate through the remaining elements
        if l[i] + l[j] > l[k]: # Check if the sum of the first two elements is greater than the third one
          cnt += 1 # Increment the counter if the condition is true
        else: # If the condition is false, break out of the inner loop
          break
  print(cnt) # Print the value of the counter to the standard output
  return 0 # End of the main function with a successful return status
