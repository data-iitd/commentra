# Include the standard input/output library

def main():  # Start of the main function
    n = int(input())  # Read an unsigned long long integer value from the standard input and store it in the variable n

    b = (n * (n - 1)) // 2  # Calculate the sum of numbers from 1 to n-1 and store the result in the variable b

    print(b)  # Print the value of b to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
