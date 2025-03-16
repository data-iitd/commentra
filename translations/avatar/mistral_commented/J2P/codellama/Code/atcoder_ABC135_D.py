
import sys

def main():
    # Read the input string
    s = sys.stdin.readline().strip()

    # Initialize the base variable to 1
    base = 1

    # Initialize the dp array
    dp = [[0] * 13 for _ in range(len(s))]

    # Iterate through each character in the input string
    for i in range(len(s)):
        if s[len(s) - 1 - i] == '?':
            # If the current character is a '?', iterate through all possible values of pre (from 0 to 12)
            for pre in range(13):
                # Iterate through all possible values of next (from 0 to 9)
                for next in range(10):
                    # Add the contribution of the current character to the dp array
                    dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (pre == 0))
                    dp[i][(base * next + pre) % 13] %= 1000000007
        else:
            # If the current character is not a '?', convert the digit character to an integer and subtract '0' to get the actual value
            next = ord(s[len(s) - 1 - i]) - ord('0')
            # Iterate through all possible values of pre (from 0 to 12)
            for pre in range(13):
                # Add the contribution of the current character to the dp array
                dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (pre == 0))
                dp[i][(base * next + pre) % 13] %= 1000000007

        # Multiply the base by 10 and take the result modulo 13 to update the base for the next character
        base = (base * 10) % 13

    # Print the final result
    print(dp[len(s) - 1][5])

if __name__ == "__main__":
    main()

