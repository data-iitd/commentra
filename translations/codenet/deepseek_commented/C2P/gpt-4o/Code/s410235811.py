# Define the main function
def main():
    n = int(input())  # Read an integer input from the user
    if n % 2 == 0:    # Check if the number n is even
        print(n // 2)  # If n is even, print half of n
    else:             # If n is not even
        print((n // 2) + 1)  # Print half of n plus one

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
