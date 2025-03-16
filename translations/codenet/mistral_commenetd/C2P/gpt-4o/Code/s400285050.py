# Function to calculate the greatest common divisor (GCD) of two numbers
def you(x, y):
    while y != 0:
        z = x % y
        x = y
        y = z
    return x

def main():
    # Read two integers from the user
    x, y = map(int, input("Enter two integers: ").split())

    # Determine which number is greater and call the you() function with the appropriate arguments
    if x >= y:
        z = you(x, y)  # Call the you() function with x and y as arguments
    else:
        z = you(y, x)  # Call the you() function with y and x as arguments

    # Print the result (the greatest common divisor) to the console
    print(f"The greatest common divisor of {x} and {y} is: {z}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
