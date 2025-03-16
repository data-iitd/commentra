
import sys

def modinv(a, m):
    b = m
    u = 1
    v = 0
    tmp = 0
    while b > 0:
        t = a // b
        a -= t * b
        tmp = a
        a = b
        b = tmp
        u -= t * v
        tmp = u
        u = v
        v = tmp
    u %= m
    if u < 0:
        u += m
    return u

def main():
    # Step 1: Read the input number n and the array elements
    n = int(input())
    a = list(map(int, input().split()))

    # Step 2: Calculate the factorial of n modulo 10^9 + 7
    mod = 1000000007
    p = 1
    for i in range(2, n + 1):
        p = p * i % mod

    # Step 3: Calculate the inverse modulo for each number from 2 to n
    q = [0] * n
    q[0] = 1
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod

    # Step 4: Calculate the answer using the given formula
    ans = 0
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1
        val *= a[i]
        val %= mod
        val *= p
        val %= mod
        ans += val
        ans %= mod

    # Step 5: Print the final answer
    print(ans)

if __name__ == '__main__':
    main()

