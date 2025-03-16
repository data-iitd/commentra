import sys

# Main Function
# The main function reads two integers, n and k, and calculates the sum of combinations from k to n+1.
# It uses a modulo operation to prevent overflow and prints the final result.
def main():
    n = read_int()  # Read the first integer, n.
    k = read_int()  # Read the second integer, k.

    total = 0  # Initialize the total sum of combinations.
    for i in range(k, n + 2):
        total += combi(n, i)  # Calculate the combination and add it to the total.
        total = total % (pow(10, 9) + 7)  # Apply modulo operation to prevent overflow.
    
    print(total)  # Print the final result.

# Combination Function
# The combi function calculates the number of combinations of choosing k items from n items.
# It uses a simplified formula to find the range of the binomial coefficient.
def combi(n, k):
    min_val = (k - 1) * k // 2  # Calculate the minimum value of the binomial coefficient.
    max_val = (2 * n - k + 1) * k // 2  # Calculate the maximum value of the binomial coefficient.
    return max_val - min_val + 1  # Return the number of combinations.

# Utility Functions
# These functions provide basic mathematical operations and input reading capabilities.

# Read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
