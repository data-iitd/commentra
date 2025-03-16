
# Import the required modules
import sys

# Initialize variable N to store the number of elements in the array
N = int(input())

# Initialize a list 'v' of size N to store the frequency of each element
v = [0] * N

# Iterate through the input elements and update the frequency in the list 'v'
for i in range(1, N):
    # Read the next element from the standard input
    a = int(input())
    # Update the frequency of the element 'a-1' in the list 'v'
    v[a-1] += 1

# Iterate through the list 'v' and print each element to the standard output
for e in v:
    # Print each element to the standard output
    print(e)

# End of the code
