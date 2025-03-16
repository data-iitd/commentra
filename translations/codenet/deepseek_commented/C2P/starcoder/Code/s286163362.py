#include <stdio.h>
#include <string.h>

# Function to return the maximum of two integers
def max(a, b):
  if a > b:
    return a;
  return b;

# Main function
def main():
  # Loop to read input values and process them
  while True:
    # Read values of n and k
    n, k = map(int, input().split())
    if n == 0 and k == 0:
      break;

    # Initialize the data and seq arrays to zero
    data = [0] * 111111;
    seq = [0] * 222222;

    # Read k numbers and store their frequencies in data
    for i in range(k):
      t = int(input())
      data[t] += 1

    # Construct the seq array based on the frequencies in data
    p = 0
    for i in range(1, n + 1):
      if data[i]:
        seq[p] += 1
      else:
        p += 2

    # Calculate the maximum value of ret based on the sequences in seq
    if data[0]:
      ret = 0
      for i in range(p):
        ret = max(ret, seq[i] + seq[i + 2] + 1)
    else:
      ret = 0
      for i in range(p):
        ret = max(ret, seq[i])

    # Print the result
    print(ret)

# Call the main function
main()

