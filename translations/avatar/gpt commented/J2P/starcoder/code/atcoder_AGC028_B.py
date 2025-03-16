import sys

def modinv(a, m):
    b = m
    u = 1
    v = 0
    tmp = 0
    while b > 0:
        t = a / b
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
    # Read the number of elements
    n = int(sys.stdin.readline())
    # Read the elements
    a = [int(x) for x in sys.stdin.readline().split()]
    # Initialize the cumulative sums
    q = [0] * n
    q[0] = 1
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, 1000000007)) % 1000000007
    # Initialize the answer
    ans = 0
    # Calculate the answer
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1
        val *= a[i]
        val %= 1000000007
        val *= p
        val %= 1000000007
        ans += val
        ans %= 1000000007
    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

