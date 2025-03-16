# Include the standard input/output library

def main():
    # Declare and initialize variables
    i = 1  # Initialize counter variable i to 1

    while True:
        # Read user input and store it in the Input variable
        Input = int(input())

        # Check if user input is 0
        if Input == 0:
            # If user input is 0, break out of the loop
            break

        # Print the case number and user input
        print(f"Case {i}: {Input}")

        # Increment the counter variable i
        i += 1

    # Return 0 to indicate successful execution of the program
    return 0

if __name__ == "__main__":
    main()

# <END-OF-CODE>
