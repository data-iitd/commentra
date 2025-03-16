# Import necessary libraries
import sys

# Define the main function
def main():
    N, X = map(int, sys.stdin.readline().split())  # Read two integers from input

    ans = 0  # Initialize the answer variable to zero
    min_value = 1000000000  # Initialize the minimum value to a large number

    for _ in range(N):  # Loop N times
        tmp = int(sys.stdin.readline().strip())  # Read an integer from input

        X -= tmp  # Subtract tmp from X
        ans += 1  # Increment ans by 1

        if tmp < min_value:  # If tmp is smaller than the current minimum value
            min_value = tmp  # Update the minimum value

    ans += X // min_value  # Add the quotient of X divided by min_value to ans

    print(ans)  # Output the value of ans

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
