# Function definition for the main function
def main():
    # Reading input values for r, D, and x from the standard input
    r, D, x = map(int, input().split())

    # Loop runs 10 times
    for i in range(10):
        # Print the result of the current iteration
        print(r * x - D)

        # Update the value of x for the next iteration
        x = r * x - D

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
