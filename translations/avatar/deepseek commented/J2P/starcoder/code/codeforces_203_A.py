import sys

# Reading the number of test cases (t) and other required values
x = int(input())
t = int(input())
a = int(input())
b = int(input())
da = int(input())
db = int(input())

# Variables to store calculated values
first = 0
second = 0

# Flag to determine if a solution is found
ok = False

# Nested loop to calculate possible values of first and second
for i in range(t):
    first = a - (da * i)
    for j in range(t):
        second = b - (db * j)
        if second + first == x or second == x or first == x or x == 0:
            # Check if the sum of first and second equals x, or if either value equals x, or if x is zero
            ok = True
            break
    if ok:
        break

# Print the result based on the flag
if ok:
    print("YES")
else:
    print("NO")

# 