# Import the standard input/output library (not needed in Python)

def main():  # Declare the main function
    a, b, h = map(int, input("Enter the values of a, b, and h: ").split())  # Read three integers from the user

    # Calculate the area of the trapezoid using the formula: area = (a + b) * h / 2
    print((a + b) * h / 2)  # Print the result, which is the area of the trapezoid

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
