# Import necessary modules
from collections import defaultdict

# Initialize some variables
d = [False] * 10  # A boolean list to keep track of digits that have been seen
n, k = map(int, input().split())  # Input variables for the number and the number of digits to check

# Check each digit in the input number 'k' times
for _ in range(k):
    a = int(input())  # Read the digit from the input
    d[a] = True  # Mark the digit as seen

# Keep generating numbers until a valid one is found
while True:
    x = n  # Initialize a variable 'x' to store the current number being checked

    # Initialize a flag 'hantei' to indicate if the current number is valid
    hantei = True

    # Check each digit in the number 'x'
    while x:
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

# <END-OF-CODE>
