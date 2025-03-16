# Include the standard input/output library

# Declare two integer variables x and y
x, y = 0, 0

# The main function is the entry point of the program
if __name__ == "__main__":
    # Print a message asking for two integers
    print("Enter two integers: ", end='')

    # Read two integers from the standard input and store them in variables x and y
    x, y = map(int, input().split())

    # Perform some arithmetic operations
    result1 = x * y  # Multiply x and y and store the result in result1
    result2 = 2 * x + 2 * y  # Multiply x by 2 and y by 2, then add the results

    # Print the results
    print(f"The product of {x} and {y} is: {result1}")  # Print the message and the product of x and y
    print(f"The sum of 2 times {x} and 2 times {y} is: {result2}")  # Print the message and the sum of 2 times x and 2 times y

# Indicate that the program has run successfully
# <END-OF-CODE>
