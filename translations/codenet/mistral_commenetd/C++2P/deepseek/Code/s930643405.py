import sys

# Read input
n, k = map(int, input().split())

# Define a boolean array to keep track of digits that have been seen
d = [0] * 10

# Check each digit in the input number 'k' times
for _ in range(k):
    a = int(input())
    d[a] = 1

# Keep generating numbers until a valid one is found
while True:
    x = n
    hantei = True

    # Check each digit in the number 'x'
    while x > 0:
        # If the current digit has already been seen, then the number is not valid
        if d[x % 10]:
            hantei = False
            break
        x //= 10  # Move to the next digit

    # If the current number is valid, print it and exit the loop
    if hantei:
        print(n)
        break

    # If the current number is not valid, increment 'n' and continue checking
    n += 1
