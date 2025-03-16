import sys

def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize a list to hold the input values
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initialize a dp list to store the maximum values
    dp = [-1] * (n + 1)
    
    # Set the last element of dp to the last element of a
    dp[n - 1] = a[n - 1]
    
    # Fill the dp list with the maximum values from the end to the beginning
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])
    
    # Prepare the output list
    output = []
    
    # Iterate through the original list to calculate the output
    for i in range(n):
        # If the current element is greater than the next maximum, append 0
        if a[i] > dp[i + 1]:
            output.append(0)
        # Otherwise, calculate and append the difference to the next maximum
        else:
            output.append(dp[i + 1] - a[i] + 1)
    
    # Print the output
    print(" ".join(map(str, output)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
