# Function to swap the values of two integers
def swap(a, b):
    tmp = a # Store the value pointed by a in tmp
    a = b    # Assign the value pointed by b to the location pointed by a
    b = tmp  # Assign the value stored in tmp to the location pointed by b

# Infinite loop to continuously read input until termination condition is met
while True:
    # Read two integers from user input
    a, b = map(int, input().split())

    # Check for the termination condition (both inputs are zero)
    if a == 0 and b == 0: break

    # If the second number is less than the first, swap them
    if b < a: swap(a, b)

    # Print the sorted values of a and b
    print(a, b)

# 