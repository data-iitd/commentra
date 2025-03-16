# Include standard input-output library for functions like printf and scanf
# Include standard library for general utilities like dynamic memory allocation
# Include library for string manipulation
# Include library for mathematical functions

# Main function where the execution of the program begins
def main():
    A = int(input())  # Read the number of each coin type and the target sum from the user
    B = int(input())
    C = int(input())
    X = int(input())

    # Normalize the target sum X by dividing it by 50
    X = X / 50

    kosu = 0  # Declare and initialize a counter for the number of combinations

    # Nested loops to iterate over all possible combinations of the coins
    for i in range(A + 1):  # Loop over the number of 500 yen coins
        for j in range(B + 1):  # Loop over the number of 100 yen coins
            for k in range(C + 1):  # Loop over the number of 50 yen coins
                if (X == (10 * i) + (2 * j) + k):  # Check if the sum of the coin values equals the normalized target sum
                    kosu = kosu + 1  # Increment the counter if the condition is met

    # Print the final count of combinations
    print(kosu)

# Call the main function
if __name__ == "__main__":
    main()

