# Function definition for 'you' which takes two integers and returns an integer
def you(x, y):
    while True:
        z = x % y  # Calculate the remainder of x divided by y
        x = y      # Update x to be y
        y = z      # Update y to be the remainder

        # Break the loop if y becomes zero or negative
        if y <= 0:
            break

    # Return the last non-zero value of x, which is the GCD
    return x

# Main function to execute the program
if __name__ == "__main__":
    # Read two integers from user input
    x, y = map(int, input().split())

    # Call the 'you' function with the larger and smaller of the two integers
    if x >= y:
        z = you(x, y)  # If x is greater than or equal to y, pass x and y to 'you'
    else:
        z = you(y, x)  # Otherwise, pass y and x to 'you'

    # Print the result returned from the 'you' function
    print(z)

# <END-OF-CODE>
