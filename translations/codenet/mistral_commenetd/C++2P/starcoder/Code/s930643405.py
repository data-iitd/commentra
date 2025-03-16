# Define a pair type alias for convenience
P = lambda x, y: (x, y)

# Initialize some variables
d = [0] * 10 # A boolean array to keep track of digits that have been seen
n, k = 0, 0 # Input variables for the number and the number of digits to check
hantei = True # A flag to indicate if the current number is a valid answer

# Read input
n, k = map(int, input().split())

# Check each digit in the input number 'k' times
for i in range(k):
    a = int(input()) # Read the digit from the input
    d[a] = 1 # Mark the digit as seen

# Keep generating numbers until a valid one is found
while True:
    x = n # Initialize a variable 'x' to store the current number being checked

    # Initialize a flag 'hantei' to indicate if the current number is valid
    hantei = True

    # Check each digit in the number 'x'
    while x:
        # If the current digit has already been seen, then the number is not valid
        if d[x % 10]:
            hantei = False
            break
        x //= 10 # Move to the next digit

    # If the current number is valid, print it and exit the loop
    if hantei:
        print(n)
        break

    # If the current number is not valid, increment 'n' and continue checking
    n += 1

# 