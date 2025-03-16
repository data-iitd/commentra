def gcd(a, b):
    while b > 0:
        c = a % b
        a = b
        b = c
    return a

def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n //= 2
    return ans

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

def main():
    n = int(input())
    sum_digits = sum(int(digit) for digit in str(n))
    if n % sum_digits == 0:
        print("Yes")
    else:
        print("No")

main()
