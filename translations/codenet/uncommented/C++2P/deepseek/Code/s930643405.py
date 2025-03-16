import sys

# Read input
n, k = map(int, input().split())
d = [0] * 10
for _ in range(k):
    a = int(input())
    d[a] = 1

# Function to check if a number is valid
def is_valid(num):
    while num > 0:
        if d[num % 10]:
            return False
        num //= 10
    return True

# Main loop to find the next valid number
while True:
    if is_valid(n):
        print(n)
        break
    n += 1
