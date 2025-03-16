MOD = 10**9 + 7

def main():
    # Read the input string and convert it to a character array
    cs = list(input())
    
    # Initialize a 2D array for dynamic programming to store results
    dp = [[0] * 13 for _ in range(len(cs))]
    
    # Variable to keep track of the base value for calculations
    base = 1
    
    # Iterate through the characters of the input from the last to the first
    for i in range(len(cs)):
        # Check if the current character is a '?', which can be any digit
        if cs[len(cs) - 1 - i] == '?':
            # Loop through all possible previous remainders
            for pre in range(13):
                # Loop through all possible next digits (0-9)
                for next in range(10):
                    # Update the dp array for the current position and remainder
                    dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else 1 if pre == 0 else 0)
                    # Ensure the result stays within the MOD limit
                    dp[i][(base * next + pre) % 13] %= MOD
        else:
            # If the character is a digit, convert it to an integer
            next = int(cs[len(cs) - 1 - i])
            # Loop through all possible previous remainders
            for pre in range(13):
                # Update the dp array for the current position and remainder
                dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else 1 if pre == 0 else 0)
                # Ensure the result stays within the MOD limit
                dp[i][(base * next + pre) % 13] %= MOD
        # Update the base value for the next iteration (moving to the next digit)
        base = base * 10 % 13
    
    # Output the result, which is the number of ways to form a number divisible by 13
    print(dp[len(dp) - 1][5])

if __name__ == "__main__":
    main()
