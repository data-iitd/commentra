# Import necessary libraries
import sys

# Main function
def main():
    n, m = map(int, sys.stdin.readline().split())  # Read input values of n and m

    ans = 0  # Initialize answer variable ans to 0

    # Calculate combinations for n
    ans += n * (n - 1) // 2  # Calculate the sum of numbers from 1 to n-1 and add it to the answer

    # Calculate combinations for m
    ans += m * (m - 1) // 2  # Calculate the sum of numbers from 1 to m-1 and add it to the answer

    print(ans)  # Print the answer to the standard output

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
