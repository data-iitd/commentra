
# Python code to swap the values of two integers

# Function to swap the values of two integers
def swap(a, b):
    tmp = a # Temporary variable to hold one of the values during swap
    a = b  # Assign the value of b to a
    b = tmp # Assign the value of tmp to b

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

# End of Python code
