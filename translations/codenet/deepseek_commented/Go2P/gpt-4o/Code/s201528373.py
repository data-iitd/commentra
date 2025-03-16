# Python translation of the provided Go code

# Read the number of elements and the target sum from the standard input
n = int(input())
x = int(input())

# Read n integers from the standard input and store them in a list
l = list(map(int, input().split()))

# Initialize variables to keep track of the sum and the result
tmp_sum = 0
rs = 0

# Iterate over the list l, updating the sum and checking the condition
for i, v in enumerate(l):
    tmp_sum += v
    # If the sum is less than or equal to x, update the result
    if tmp_sum <= x:
        rs = i + 2
    else:
        break

# Print the result
print(rs)

# <END-OF-CODE>
