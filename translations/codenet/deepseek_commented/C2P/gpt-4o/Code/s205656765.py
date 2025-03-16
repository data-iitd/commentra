# Import necessary libraries
import sys

# Main function where the execution of the program begins
def main():
    # Read the number of each coin type and the target sum from the user
    A = int(input())  # Number of 500 yen coins
    B = int(input())  # Number of 100 yen coins
    C = int(input())  # Number of 50 yen coins
    X = int(input())  # Target sum

    # Normalize the target sum X by dividing it by 50
    X = X // 50

    # Initialize a counter for the number of combinations
    kosu = 0

    # Nested loops to iterate over all possible combinations of the coins
    for i in range(A + 1):  # Loop over the number of 500 yen coins
        for j in range(B + 1):  # Loop over the number of 100 yen coins
            for k in range(C + 1):  # Loop over the number of 50 yen coins
                if X == (10 * i) + (2 * j) + k:  # Check if the sum of the coin values equals the normalized target sum
                    kosu += 1  # Increment the counter if the condition is met

    # Print the final count of combinations
    print(kosu)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
