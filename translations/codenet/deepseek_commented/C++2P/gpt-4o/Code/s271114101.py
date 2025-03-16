# Include the necessary library for input and output operations

# Define the main function
def main():
    # Declare three integer variables 'a', 'b', and 'c'
    a, b, c = map(int, input().split())  # Read three integers from the standard input

    # Check if any of the following conditions are true:
    # - a + b equals c
    # - b + c equals a
    # - a + c equals b
    if a + b == c or b + c == a or a + c == b:
        print("Yes")  # If any condition is true, print "Yes"
    else:
        print("No")   # Otherwise, print "No"

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
