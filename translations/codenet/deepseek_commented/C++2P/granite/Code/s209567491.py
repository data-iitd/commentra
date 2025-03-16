
import sys

# Read input
N, D, X = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

# Calculate the number of chocolates
num_of_chocolate = 0
for i in range(N):
    days = 0
    counter = 0
    while True:
        days = j * A[i] + 1
        if days <= D:
            counter += 1
        else:
            break
    num_of_chocolate += counter

# Add extra chocolates
num_of_chocolate += X

# Print the result
print(num_of_chocolate)

