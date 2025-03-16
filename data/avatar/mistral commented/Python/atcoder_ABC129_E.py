# Modulus constant for fast modular arithmetic
mod = 10 ** 9 + 7

# Read input string length
l = input ()
n = len ( l )

# Initialize 2D dynamic programming table
dp = [ [ 0 ] * 2 for _ in range ( n + 1 ) ]

# Base case: empty string has 1 solution
dp [ 0 ] [ 0 ] = 1

# Iterate through each character in the input string
for i, c in enumerate ( l ) :
    # Update dp[i+1][0] based on current character '0' or '1'
    if c == '0' :
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ]
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3
    else :
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ] * 2
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 0 ]
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3

    # Perform modular arithmetic to keep the values within the modulus
    dp [ i + 1 ] [ 0 ] %= mod
    dp [ i + 1 ] [ 1 ] %= mod

# Calculate the final answer
print ( ( dp [ n ] [ 0 ] + dp [ n ] [ 1 ] ) % mod )
