import sys

# Read the number of elements
n = int(input().strip())

# Initialize sums
a = 0
b = 0
c = 0

# Read the first sequence of numbers
a_sequence = list(map(int, input().strip().split()))
for num in a_sequence:
    a += num

# Read the second sequence of numbers
b_sequence = list(map(int, input().strip().split()))
for num in b_sequence:
    b += num

# Read the third sequence of numbers
c_sequence = list(map(int, input().strip().split()))
for num in c_sequence:
    c += num

# Calculate the differences
x = a - b
y = b - c

# Print the results
print(x)
print(y)
