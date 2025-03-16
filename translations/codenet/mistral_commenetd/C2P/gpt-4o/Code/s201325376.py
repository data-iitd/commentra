# Include the standard input/output library

def main():  # The entry point of the program
    a, b, c = map(int, input().split())  # Read three integers a, b, and c from the standard input
    count = 0  # Initialize the count variable to zero

    # The following for loop iterates from the value of 'a' to the value of 'b'
    for i in range(a, b + 1):
        # Check if 'c' is divisible by 'i'
        if c % i == 0:
            # If it is, increment the count variable
            count += 1

    # Print the value of 'count' to the standard output
    print(count)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
