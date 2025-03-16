def you(x, y):  # Define the you function
    while True:  # Infinite loop to apply the Euclidean algorithm
        z = x % y  # Compute the remainder of x divided by y
        x = y  # Update x to be the previous value of y
        y = z  # Update y to be the remainder
        if y <= 0:  # Check if y is zero or negative
            break  # Exit the loop if y is zero or negative
    return x  # Return the GCD of the original two numbers

if __name__ == "__main__":  # Main function is the entry point of the program
    x, y = map(int, input().split())  # Read two integers from standard input
    if x >= y:  # Check if x is greater than or equal to y
        z = you(x, y)  # Call the you function with x and y as arguments
    else:  # Otherwise
        z = you(y, x)  # Call the you function with y and x as arguments
    print(z)  # Print the result to standard output

# <END-OF-CODE>
