

import sys

# Function to calculate the number of digits in a given long integer
def power(a):
    res = 0
    while a > 0:
        res += 1
        a //= 10
    return res

# Function to calculate the maximum product of two numbers formed by splitting the given number into two parts
def mult(a):
    pow = power(a)
    maxx = 0
    for j in range(pow):
        maxx = maxx * 10 + 9
    return a * (maxx - a)

# Read two long integers from the input
l, r = map(int, sys.stdin.readline().split())
res = 0
maxxes = [0] * 10
temp = 0

# Calculate the maximum product for each range and store it in the array maxxes
for i in range(10):
    temp = temp * 10 + 9
    maxxes[i] = temp // 2 * (temp - temp // 2)

# Calculate the maximum product for the given ranges and update the result res
res = max(mult(l), res)
res = max(mult(r), res)
temp = 0

# Check if the middle value of the range is within the given range and update the result res accordingly
for i in range(10):
    temp = temp * 10 + 9
    if l <= temp // 2 <= r:
        res = max(maxxes[i], res)

# Print the final result
print(res)

