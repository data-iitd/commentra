# Import the necessary module for reading input
import sys

# Define the main function
def main():
    # Read the first two integers from the standard input
    N, K = map(int, sys.stdin.readline().split())  # Read the number of elements and the size of the sliding window

    # Allocate a list to store the input elements
    S = list(map(int, sys.stdin.readline().split()))  # Read the remaining elements of the array

    # Initialize variables for calculating the answer
    temp = 0
    ans = 1000000000

    # Check the special case when the size of the sliding window is 1
    if K == 1:
        # Iterate through the array to find the minimum absolute value
        for i in range(N):
            temp = S[i]  # Read the current element
            ans = min(abs(temp), ans)  # Update the answer if necessary

        # Print the answer
        print(ans)
    elif N - K != 0:  # Check the case when the size of the sliding window is not equal to the size of the array
        # Initialize variables for calculating the minimum and maximum elements in the sliding window
        min_val, max_val = 0, 0

        # Iterate through all possible positions of the sliding window
        for i in range(N - K + 1):
            # Find the minimum and maximum elements in the current sliding window
            min_val = S[i]
            max_val = S[i + K - 1]

            # Calculate the sum of the absolute values of the minimum and maximum elements
            # and update the answer if necessary
            if min_val < 0 and max_val > 0:
                temp = 2 * abs(min_val) + max_val
            else:
                temp = max(abs(min_val), abs(max_val))
            ans = min(ans, temp)

        # Print the answer
        print(ans)
    else:  # Check the case when the size of the sliding window is equal to the size of the array
        # Find the minimum and maximum elements in the array
        min_val = S[0]
        max_val = S[N - 1]

        # Calculate the sum of the absolute values of the minimum and maximum elements
        # and print the answer directly
        if min_val < 0 and max_val > 0:
            print(min(2 * abs(min_val) + max_val, abs(min_val) + 2 * max_val))
        else:
            print(max(abs(min_val), abs(max_val)))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
