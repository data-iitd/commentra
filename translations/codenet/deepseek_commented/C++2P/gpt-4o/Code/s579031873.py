# Import necessary libraries
import sys

# Define the main function
def main():
    N, X = map(int, sys.stdin.readline().split())  # Read the values of N and X from the standard input

    ans = 0  # Initialize the answer variable
    min_value = 1000000000  # Initialize the minimum value variable
    for _ in range(N):  # Loop through N elements
        tmp = int(sys.stdin.readline().strip())  # Read the value into the temporary variable
        X -= tmp  # Subtract the value from X
        ans += 1  # Increment the answer count
        if tmp < min_value:  # Update the minimum value if the current value is smaller
            min_value = tmp

    ans += X // min_value  # Calculate the final answer by adding the quotient of X divided by the minimum value

    print(ans)  # Print the final answer to the standard output

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
