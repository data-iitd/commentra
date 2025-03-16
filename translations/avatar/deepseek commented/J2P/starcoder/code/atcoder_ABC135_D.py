import sys

# MOD constant with value 10^9 + 7
MOD = 1000000007

# Main logic of the program
def run():
    # Read the input
    s = sys.stdin.readline().strip()

    # 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
    dp = [[0 for _ in range(13)] for _ in range(len(s))]

    # Initialize the base variable to represent the current power of 10
    base = 1

    # Loop through the character array from the least significant digit to the most significant digit
    for i in range(len(s)):
        if s[len(s) - 1 - i] == '?':
            # If the current character is '?', we iterate through all possible digits (0-9)
            for pre in range(13):
                for next in range(10):
                    dp[i][(base * next + pre) % 13] += (i > 0) * dp[i - 1][pre]
                    dp[i][(base * next + pre) % 13] %= MOD
        else:
            # If the current character is not '?', we update the dp array based on the actual digit
            next = int(s[len(s) - 1 - i])
            for pre in range(13):
                dp[i][(base * next + pre) % 13] += (i > 0) * dp[i - 1][pre]
                dp[i][(base * next + pre) % 13] %= MOD

        # Update the base variable to the next power of 10 modulo 13
        base = base * 10 % 13

    # Print the number of ways to achieve the remainder 5 when the number is divided by 13
    print(dp[len(s) - 1][5])

# Method to print debug information (optional)
def tr(*objects):
    print(*objects, file=sys.stderr)

# Main function
if __name__ == '__main__':
    run()

