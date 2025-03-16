import sys

# Define an array to keep track of unavailable digits
d = [0] * 10

# Define variables to store the number and the number of unavailable digits
n, k = map(int, input().split())

# Mark the unavailable digits
for _ in range(k):
    a = int(input())
    d[a] = 1

# Loop until a valid number is found
while True:
    # Copy the current number to a temporary variable and initialize the check flag
    x = n
    hantei = True

    # Check each digit of the number
    while x > 0:
        # If a digit is unavailable, set the check flag to false and break the loop
        if d[x % 10]:
            hantei = False
            break
        # Move to the next digit
        x //= 10

    # If the number is valid, print it and break the loop
    if hantei:
        print(n)
        break

    # Increment the number and check again
    n += 1
