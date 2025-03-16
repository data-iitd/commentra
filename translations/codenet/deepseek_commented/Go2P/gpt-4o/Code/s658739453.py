d = 1000000007

def main():
    n = int(input())  # Read the value of n from standard input
    p = int(input())  # Read the value of p from standard input

    mdans = {}
    for _ in range(p):
        n1 = int(input())  # Read each value into the dictionary mdans
        mdans[n1] = n1

    dp = [0] * (n + 1)  # Initialize the dp list
    dp[0] = 1  # Initialize the first element of dp list
    dp[1] = 1  # Initialize the second element of dp list

    if 1 in mdans:  # Check if the value 1 is in the dictionary mdans
        dp[1] = 0  # Set dp[1] to 0 if 1 is in the dictionary

    for i in range(2, n + 1):
        if i in mdans:  # Check if the current value i is in the dictionary mdans
            continue  # Skip to the next iteration if i is in the dictionary
        dp[i] = (dp[i - 1] + dp[i - 2]) % d  # Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo d

    print(dp[n])  # Print the value at dp[n]

if __name__ == "__main__":
    main()

# <END-OF-CODE>
