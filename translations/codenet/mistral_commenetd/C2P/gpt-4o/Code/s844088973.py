# Include the standard input/output library

def main():  # Start of the main function
    K, X = map(int, input().split())  # Read two integers from the standard input and store them in variables K and X

    for i in range(X - K + 1, X + K):  # Start of the for loop
        print(i, end='')  # Print the current value of i to the standard output
        if i < X + K - 1:  # If the current value of i is less than X + K - 1
            print(" ", end='')  # Print a space before the number

    print()  # Print a newline character to move the cursor to the next line

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
