
import sys

# Read input values for n, k, and q
n, k, q = map(int, input().split())

# Initialize points for each participant to k
point = [k] * n

# Process each question and update points for the corresponding participant
for _ in range(q):
    a = int(input()) - 1
    point[a] += 1

# Determine if each participant has enough points to win
for i in range(n):
    if k - (q - point[i]) > 0:
        print("Yes")
    else:
        print("No")

print("