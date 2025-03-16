# Importing necessary libraries
import math

# Main function
def main():
    n, m = map(int, input().split())

    # Initialize answer
    ans = 0

    # Calculate combinations for n
    ans += n * (n - 1) // 2

    # Calculate combinations for m
    ans += m * (m - 1) // 2

    # Print the result
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
