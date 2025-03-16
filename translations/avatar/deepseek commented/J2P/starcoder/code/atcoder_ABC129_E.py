import sys; # Importing the sys module for input

def main():
    s = sys.stdin.readline().strip(); # Reading the input string and stripping the newline character
    n = len(s); # Getting the length of the input string
    dp = [[0, 0] for i in range(n + 1)]; # Initializing the dynamic programming table
    dp[0][0] = 1; # Setting the base case for dp[0][0]

    # Iterating through each character of the input string
    for i in range(n):
        if s[i] == '0':
            dp[i + 1][0] = dp[i][0]; # Copying the previous state for '0'
            dp[i + 1][1] = dp[i][1]; # Copying the previous state for '0'
        else:
            dp[i + 1][1] = (dp[i][0] + dp[i][1]) % 1000000007; # Updating dp[i+1][1] for '1'

        # Additional updates for '0' and '1'
        if s[i] == '0':
            dp[i + 1][1] += (dp[i][1] * 2) % 1000000007; # Updating dp[i+1][1] for '0'
            dp[i + 1][1] %= 1000000007; # Ensuring the value stays within the modulo range
        else:
            dp[i + 1][0] += (dp[i][0] * 2) % 1000000007; # Updating dp[i+1][0] for '1'
            dp[i + 1][1] += (dp[i][1] * 2) % 1000000007; # Updating dp[i+1][1] for '1'
            dp[i + 1][0] %= 1000000007; # Ensuring the value stays within the modulo range
            dp[i + 1][1] %= 1000000007; # Ensuring the value stays within the modulo range
    print((dp[n][0] + dp[n][1]) % 1000000007); # Printing the result as the sum of dp[n][0] and dp[n][1] modulo M

if __name__ == "__main__":
    main();

