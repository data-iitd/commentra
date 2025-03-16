# Include the standard input/output library

def main():  # Define the main function
    x = 0  # Initialize the variable x to 0
    N = int(input())  # Read input from the user and store it in N
    for i in range(1, N + 1):  # Loop through numbers from 1 to N
        x += i  # Add each number to x
    print(x)  # Print the final value of x

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
