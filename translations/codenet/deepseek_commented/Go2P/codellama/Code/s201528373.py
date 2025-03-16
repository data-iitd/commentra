
# Declare variables to hold the number of elements, the target sum, and the list of integers
n = int(input())
x = int(input())
l = []

# Read n integers from the standard input and append them to the list l
for i in range(n):
    tmpL = int(input())
    l.append(tmpL)

# Initialize variables to keep track of the sum and the result
tmpSum = 0
rs = 0

# Iterate over the list l, updating the sum and checking the condition
for i, v in enumerate(l):
    tmpSum += v
    # If the sum is less than or equal to x, update the result
    if tmpSum <= x:
        rs = i + 2
    else:
        break

# Print the result
print(rs)

