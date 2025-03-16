# Include the standard input/output library

def main():  # The entry point of the program
    a, b = map(int, input().split())  # Read two integers from the standard input and store them in variables 'a' and 'b'
    
    print((b - 1 + (a - 2)) // (a - 1))  # Print the result of the expression ((b-1)+(a-2))/(a-1) to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
