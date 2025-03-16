# Include the standard input/output library

# Declare variables
def main():
    a, b = map(int, input().split())  # Read input values for variables a and b from the user
    mawari = a + a + b + b  # Assign the variable mawari the sum of the squares of a and b
    menseki = a * b  # Assign the variable menseki the product of a and b
    print(menseki, mawari)  # Print the values of menseki and mawari to the console

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
