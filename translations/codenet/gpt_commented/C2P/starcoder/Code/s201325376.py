# <START-OF-CODE>

# Read three integers from user input: a, b, and c
a, b, c = map(int, input().split())

# Initialize count to zero to keep track of how many numbers in the range divide c
count = 0

# Loop through each integer i from a to b (inclusive)
for i in range(a, b + 1):
    # Check if c is divisible by i
    if c % i == 0:
        # If divisible, increment the count
        count += 1

# Print the total count of numbers that divide c
print(count)

# 