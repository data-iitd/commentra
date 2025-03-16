# Read two integers from input: n (number of elements) and x (target sum)
n, x = map(int, input().split())

# Read n integers from input and store them in a list m
m = [int(input()) for _ in range(n)]

# Sort the list m in ascending order
m.sort()

# Calculate and print the result:
# The result is the number of elements n plus the integer division of the difference
# between x and the sum of elements in m by the smallest element in m (m[0])
print(n + (x - sum(m)) // m[0])
