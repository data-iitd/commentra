# Function to be executed when the script is run directly
def main():
    # Read input values X, K, and D from the user
    X, K, D = map(int, input().split())

    # Calculate the quotient of X by D
    r = X // D

    # Check if the absolute value of the quotient is greater than K
    if abs(r) > K:
        # If yes, print the difference between X and K * D
        print(abs(X) - K * D)
        # Exit the function as there is no need to continue further
        exit()

    # Calculate the remainder of X by D
    a = X - r * D

    # Check if the difference between K and the quotient is even
    if (K - r) % 2 == 0:
        # If yes, print the remainder a
        print(a)
    else:
        # If no, print the absolute difference between D and the remainder
        print(abs(D - a))

# Run the main function if the script is run directly
if __name__ == '__main__':
    main()
