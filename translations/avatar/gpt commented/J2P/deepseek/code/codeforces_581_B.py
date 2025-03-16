import sys

def main():
    # Read the number of elements
    n = int(input().strip())
    
    # Read the input values into an array
    a = list(map(long, input().strip().split()))
    
    # Initialize a dp array to store the maximum values
    dp = [-1] * (n + 1)
    
    # Set the last element of dp to the last element of a
    dp[n - 1] = a[n - 1]
    
    # Fill the dp array with the maximum values from the end to the beginning
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])
    
    # Iterate through the original array to calculate the output
    for i in range(n):
        # If the current element is greater than the next maximum, print 0
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        # Otherwise, calculate and print the difference to the next maximum
        else:
            print((dp[i + 1] - a[i] + 1), end=' ')
    print()

if __name__ == "__main__":
    main()
