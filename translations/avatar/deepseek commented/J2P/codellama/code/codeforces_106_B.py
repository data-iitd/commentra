
import sys

# Initialize Scanner to read input from standard input
input = sys.stdin

# Initialize PrintWriter to write output to standard output
out = sys.stdout

# Read the number of elements
n = int(input.readline())

# Initialize a 2D array to store the elements
vec = [[0 for i in range(4)] for j in range(n)]

# Read the elements into the 2D array
for i in range(n):
    vec[i][0] = int(input.readline())
    vec[i][1] = int(input.readline())
    vec[i][2] = int(input.readline())
    vec[i][3] = int(input.readline())

# Initialize variables to store the best index and its price
ans = 500
ansprice = 20000

# Loop through each element to find the best one
for i in range(n):
    fl = 1 # Flag to check if the element is dominated

    # Compare the current element with every other element
    for j in range(n):
        if vec[i][0] < vec[j][0] and vec[i][1] < vec[j][1] and vec[i][2] < vec[j][2]:
            fl = 0 # The element is dominated

    # If the element is not dominated, check its price
    if fl == 1:
        if vec[i][3] < ansprice:
            ansprice = vec[i][3] # Update the minimum price
            ans = i + 1 # Update the best index

# Output the index of the best element
out.write(str(ans) + '\n')

# Close the PrintWriter to release resources
out.close()

