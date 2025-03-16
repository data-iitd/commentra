MOD = int(1e9) + 7  # Final constant for the modulus value

def main():
    cs = input().strip()  # Read the input string
    dp = [[0] * 13 for _ in range(len(cs))]  # Create a 2D list dp of size len(cs) x 13 to store the intermediate results
    base = 1  # Initialize the base variable to 1

    # Iterate through each character in the string cs
    for i in range(len(cs)):
        if cs[len(cs) - 1 - i] == '?':  # If the current character is a '?'
            for pre in range(13):  # Iterate through all possible values of pre (from 0 to 12)
                for next in range(10):  # Iterate through all possible values of next (from 0 to 9)
                    dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (1 if pre == 0 else 0))
                    dp[i][(base * next + pre) % 13] %= MOD  # Perform modulo operation to keep the result within the range of MOD
        else:  # If the current character is not a '?'
            next = int(cs[len(cs) - 1 - i])  # Convert the digit character to an integer
            for pre in range(13):  # Iterate through all possible values of pre (from 0 to 12)
                dp[i][(base * next + pre) % 13] += (dp[i - 1][pre] if i > 0 else (1 if pre == 0 else 0))
                dp[i][(base * next + pre) % 13] %= MOD  # Perform modulo operation to keep the result within the range of MOD
        base = base * 10 % 13  # Multiply the base by 10 and take the result modulo 13 to update the base for the next character

    # Print the final result
    print(dp[len(cs) - 1][5])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
