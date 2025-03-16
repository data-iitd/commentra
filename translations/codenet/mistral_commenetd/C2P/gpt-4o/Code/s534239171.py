# Include standard input/output library

def main():  # Beginning of main function
    a, b = map(int, input("Enter two integers: ").split())  # Read two integers from standard input and store in variables a and b
    n = (a + b) // 2  # Calculate the average of a and b and store the result in variable n
    print(f"The average of {a} and {b} is: {n}")  # Display the average on standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
