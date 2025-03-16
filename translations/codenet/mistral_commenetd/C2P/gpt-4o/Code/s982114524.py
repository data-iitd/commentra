# The main function is the starting point of the program
def main():
    N = int(input("Enter a number: "))  # Prompt the user to enter a number
    x = 0  # Initialize x to 0

    # Use a for loop to iterate from 1 to N and sum up the numbers
    for i in range(1, N + 1):
        x += i  # Add the current value of i to x

    # Print the sum of the numbers to the console
    print(f"The sum of numbers from 1 to {N} is: {x}")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
