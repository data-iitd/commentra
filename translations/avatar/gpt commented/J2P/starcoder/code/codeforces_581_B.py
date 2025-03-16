
# Declare a static set to hold long values (not used in this code)
set = set()

def main():
    # Create a Scanner object for input and output
    in_ = input()
    out_ = open('output.txt', 'w')

    # Read the number of elements
    n = int(in_.readline())

    # Initialize an array to hold the input values
    a = [0] * n

    # Populate the array with input values
    for i in range(n):
        a[i] = int(in_.readline())

    # Initialize a dp array to store the maximum values
    dp = [0] * (n + 1)

    # Fill the dp array with -1 to indicate uninitialized values
    for i in range(n + 1):
        dp[i] = -1

    # Set the last element of dp to the last element of a
    dp[n - 1] = a[n - 1]

    # Fill the dp array with the maximum values from the end to the beginning
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])

    # Iterate through the original array to calculate the output
    for i in range(n):
        # If the current element is greater than the next maximum, print 0
        if a[i] > dp[i + 1]:
            out_.write(str(0) + " ")
        # Otherwise, calculate and print the difference to the next maximum
        else:
            out_.write(str(dp[i + 1] - a[i] + 1) + " ")

    # Print a new line after all outputs
    out_.write("\n")

    # Close the output file
    out_.close()

if __name__ == '__main__':
    main()

