def mod_pow(x, n, mod):
    ans = 1
    while n > 0:
        if n & 1:  # Check if the least significant bit is 1
            ans = ans * x % mod  # Update ans if the bit is set
        x = x * x % mod  # Square x and take modulo mod
        n >>= 1  # Shift n right by 1 bit (divide by 2)
    return ans


def comb_s(n, r, mod):
    tmp_n = 1
    tmp_d = 1
    ans = 1
    for i in range(1, r + 1):
        tmp_n = (tmp_n * (n + 1 - i)) % mod  # Compute the numerator
        tmp_d = (tmp_d * i) % mod  # Compute the denominator
        ans = tmp_n * mod_pow(tmp_d, mod - 2, mod) % mod  # Compute the combination
    return ans


if __name__ == "__main__":
    n = int(input())
    a = int(input())
    b = int(input())
    mod = 1000000007
    ans = mod_pow(2, n, mod)  # Calculate 2^n % MOD
    ans -= 1  # Subtract 1 from ans
    tmp_nd = comb_s(n, a, mod)  # Calculate C(n, a) % MOD
    ans = (ans - tmp_nd) % mod  # Subtract the combination from ans
    while ans < 0:  # Handle negative results
        ans += mod

    tmp_nd = comb_s(n, b, mod)  # Calculate C(n, b) % MOD
    ans = (ans - tmp_nd) % mod  # Subtract the combination from ans
    while ans < 0:  # Handle negative results
        ans += mod

    print(ans)  # Output the final result
