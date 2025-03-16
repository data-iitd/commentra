# Define two integer variables N and S for input and output respectively
N = 0
S = 0

while True:
    try:
        # Read input for N
        N = int(input())
        if N <= 0:
            break  # Exit the loop if N is not positive

        # Initialize variables M, m, and addup with default values
        M = -1  # Initialize M as an invalid value to represent the minimum sum of subarrays
        m = 1001  # Initialize m as a large value to represent the maximum sum of subarrays
        addup = 0  # Initialize addup as a variable to store the sum of all subarrays

        # Run the loop N times
        for i in range(N):
            # Read the next integer S from the user input
            S = int(input())
            # Add the current subarray sum S to the total sum addup
            addup += S
            # Update M if the current subarray sum is larger than the current minimum sum
            if S > M:
                M = S
            # Update m if the current subarray sum is smaller than the current maximum sum
            if S < m:
                m = S

        # Calculate and print the average of the differences between the maximum and minimum sums of all subarrays
        if N > 2:
            print((addup - M - m) // (N - 2))
        else:
            print(0)  # Handle case where N <= 2 to avoid division by zero

    except EOFError:
        break  # Exit the loop on end of input

# <END-OF-CODE>
