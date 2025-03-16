from collections import defaultdict

d = 1000000007  # Define a constant 'd'

def main():
    # Initialize variables
    n = int(input())  # Read the first integer 'n' from the standard input
    p = int(input())  # Read the second integer 'p' from the standard input

    mdans = set()  # Initialize an empty set 'mdans' for storing distinct numbers

    # Read 'p' distinct numbers from the standard input and store them in the set 'mdans'
    for _ in range(p):
        n1 = int(input())
        mdans.add(n1)  # Store the number 'n1' in the set 'mdans'

    dp = [0] * (n + 1)  # Initialize an array 'dp' of size 'n+1' with a default value of '0'
    dp[0] = 1  # Initialize the first element of the array 'dp' with a value of '1'
    dp[1] = 1  # Initialize the second element of the array 'dp' with a value of '1'

    # Initialize the second element of the array 'dp' with a value of '0' if the number '1' is present in the set 'mdans'
    if 1 in mdans:
        dp[1] = 0

    # Calculate the remaining elements of the array 'dp' using the previous elements
    for i in range(2, n + 1):
        if i in mdans:
            continue  # Skip the current iteration if the number 'i' is present in the set 'mdans'
        dp[i] = (dp[i - 1] + dp[i - 2]) % d  # Calculate the current element of the array 'dp'

    # Print the final result
    print(dp[n])  # Print the value of the last element of the array 'dp'

if __name__ == "__main__":
    main()

# <END-OF-CODE>
