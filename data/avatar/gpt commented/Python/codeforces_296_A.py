# Read an integer input n which represents the threshold for majority
n = int(input())

# Read a line of input, split it into a list of strings, and store it in m
m = input().split()

# Initialize a variable to track if a majority element is possible
possible = True

# Iterate through each unique element in the list m
for i in set(m):
    # Check if the count of the current element i is greater than or equal to n/2 + 1
    if m.count(i) >= n / 2 + 1:
        # If it is, set possible to False and break the loop
        possible = False
        break

# Print 'YES' if a majority element is not found, otherwise print 'NO'
print('YES' if possible else 'NO')
