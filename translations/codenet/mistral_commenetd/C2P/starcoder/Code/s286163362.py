
#include <stdio.h>
#include <string.h>

def max(a,b): # Declare a function'max' that returns the maximum of two integers.
  if a > b: # If 'a' is greater than 'b', return 'a' as the maximum.
    return a;
  return b; # Otherwise, return 'b' as the maximum.

data = [0]*111111; # Initialize an array 'data' of size 111111 for storing the frequency of each number.
seq = [0]*222222; # Initialize an array'seq' of size 222222 for storing the sequence numbers.

while True: # Start an infinite loop.

  n,k = map(int,raw_input().split()) # Read the number of elements 'n' and the size of the sequence 'k' from the standard input.
  if not n and not k: break # If both 'n' and 'k' are zero, break the loop.

  for i in range(k): # Loop through each number in the sequence.
    t = int(raw_input()) # Read a number 't' from the standard input.
    data[t] += 1 # Increment the frequency of the number 't' in the 'data' array.

  p = 0 # Initialize a pointer 'p' to the first element of the'seq' array.
  for i in range(1,n+1): # Loop through each number from 1 to 'n'.
    if data[i]: # If the frequency of the number 'i' is not zero, increment the corresponding element in the'seq' array.
      seq[p] += 1
    else: # If the frequency of the number 'i' is zero, move the pointer 'p' to the next even index.
      p += 2

  p += 1 # Increment the pointer 'p' to the next index.

  if data[0]: # If the frequency of the number 0 is not zero, calculate the maximum sum of consecutive sequences in the'seq' array.
    ret = 0
    for i in range(p):
      ret = max(ret,seq[i]+seq[i+2]+1) # Calculate the sum of the current and next sequence and update the maximum sum if necessary.
  else: # If the frequency of the number 0 is zero, calculate the maximum sum of sequences in the'seq' array.
    ret = 0
    for i in range(p):
      ret = max(ret,seq[i]) # Calculate the sum of the current sequence and update the maximum sum if necessary.

  print ret # Print the maximum sum of sequences to the standard output.

