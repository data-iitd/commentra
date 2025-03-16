def main():
    # Read the first two integers from the standard input
    N, K = map(int, input().split())

    # Read the remaining elements of the array from the standard input
    S = list(map(int, input().split()))

    # Initialize variables for calculating the answer
    temp = 0
    ans = 1000000000

    # Check the special case when the size of the sliding window is 1
    if K == 1:
        # Iterate through the array to find the minimum absolute value
        for i in range(N):
            temp = S[i]
            ans = min(abs(temp), ans)

        # Print the answer
        print(ans)
    elif N - K != 0:
        # Initialize variables for calculating the minimum and maximum elements in the sliding window
        min_val, max_val = float('inf'), float('-inf')

        # Iterate through all possible positions of the sliding window
        for i in range(N - K + 1):
            # Find the minimum and maximum elements in the current sliding window
            min_val = min(S[i:i+K])
            max_val = max(S[i:i+K])

            # Calculate the sum of the absolute values of the minimum and maximum elements
            # and update the answer if necessary
            if min_val < 0 and max_val > 0:
                temp = 2 * abs(min_val) + max_val
            else:
                temp = max(abs(min_val), abs(max_val))
            ans = min(ans, temp)

        # Print the answer
        print(ans)
    else:
        # Find the minimum and maximum elements in the array
        min_val = min(S)
        max_val = max(S)

        # Calculate the sum of the absolute values of the minimum and maximum elements
        # and print the answer directly
        if min_val < 0 and max_val > 0:
            print(min(2 * abs(min_val) + max_val, abs(min_val) + 2 * max_val))
        else:
            print(max(abs(min_val), abs(max_val)))


# Call the main function
main()

