
# Read an array of integers from standard input
arr = list(map(int, input().split()))

# Assign the first two elements of the array to variables a and b
a, b = arr[0], arr[1]

# Initialize the number of taps needed to 0
tap = 0

# Initialize the consent variable to 1 (the starting point)
consent = 1

# Loop until the consent value is less than b
while consent < b:
    # Update consent by adding (a - 1) to it
    consent = consent + a - 1
    # Increment the tap count
    tap += 1

# Print the total number of taps needed
print(tap)

