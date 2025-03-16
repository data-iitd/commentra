# Read an integer input from the user
n = input()

# Read a list of integers from the user input and convert them to a list of integers
l = list(map(int, input().split()))

# Find the maximum value in the list
b = max(l)

# Calculate the sum of all values in the list
s = sum(l)

# Check if the maximum value is less than the sum of the other values
if b < s - b:
    # If true, print 'Yes'
    print('Yes')
else:
    # If false, print 'No'
    print('No')
