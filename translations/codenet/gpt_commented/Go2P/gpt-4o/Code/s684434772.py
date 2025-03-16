import sys

def main():
    # Read two integers n and k from input
    n = read_int()
    k = read_int()

    # Initialize a variable to hold the total count
    total = 0

    # Calculate the total combinations from k to n+1
    for i in range(k, n + 2):
        total += combi(n, i)  # Add combinations for the current i
        total = total % (pow(10, 9) + 7)  # Apply modulo to prevent overflow

    # Print the final total
    print(total)

# combi calculates the number of combinations based on the given n and k
def combi(n, k):
    # Calculate the minimum and maximum possible values for combinations
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    # Return the count of combinations
    return max_val - min_val + 1

# Read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
