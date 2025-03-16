# Import necessary libraries
MOD = 10**9 + 7

# Main function
def main():
    # Initialize variables
    n, k = map(int, input().split())

    # Calculate the maximum number of unique elements in a subset of size k from 1 to n
    mx = n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2

    # Calculate the minimum number of unique elements in a subset of size k from 1 to n
    mn = k * (k - 1) // 2

    # Initialize result variable
    res = 0

    # Iterate through all possible subset sizes from k to n+1
    for i in range(k, n + 2):
        # Calculate the number of unique elements in the current subset
        res += mx - mn + 1

        # Update the maximum and minimum number of unique elements for the next iteration
        mx += n - i
        mn += i

        # Update the result variable
        res %= MOD

    # Print the final result
    print(res)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
