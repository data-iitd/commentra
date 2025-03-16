

MOD = 1000000007

def mod_pow(x, n):
    # Function to calculate x raised to the power n modulo MOD
    ans = 1
    while n > 0:
        # While n is greater than 0
        if (n & 1) == 1:
            # If n is odd
            ans = ans * x % MOD
            # Multiply ans with x
        x = x * x % MOD
        # Square x and update ans
        n >>= 1
        # Divide n by 2
    return ans

def comb_s(n, r):
    # Function to calculate nCr (n choose r) using combinatorics formula
    tmp_n = 1
    tmp_d = 1
    ans = 1
    # Initialize temporary variables tmp_n and tmp_d to 1
    for i in range(1, r + 1):
        # Loop from i=1 to i=r
        tmp_n = (tmp_n * (n + 1 - i)) % MOD
        # Multiply tmp_n with (n+1-i)
        tmp_d = (tmp_d * i) % MOD
        # Multiply tmp_d with i
        ans = tmp_n * pow(tmp_d, MOD - 2, MOD)
        # Calculate ans = tmp_n * (tmp_d^(MOD-2))
    return ans

if __name__ == "__main__":
    # Read input values of n, a, and b from the user
    n = int(input())
    a = int(input())
    b = int(input())

    ans = pow(2, n, MOD)
    # Calculate 2^n
    ans -= 1
    # Subtract 1 from the result

    tmp_nd = comb_s(n, a)
    # Calculate nCa

    ans = (ans - tmp_nd) % MOD
    # Subtract nCa from the result

    while ans < 0:
        # If the result is negative, add MOD to make it positive
        ans += MOD

    tmp_nd = comb_s(n, b)
    # Calculate nCb

    ans = (ans - tmp_nd) % MOD
    # Subtract nCb from the result

    while ans < 0:
        # If the result is negative, add MOD to make it positive
        ans += MOD

    print(ans)
    # Print the final answer

