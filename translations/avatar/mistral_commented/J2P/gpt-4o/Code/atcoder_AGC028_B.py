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
    n = int(sys.stdin.readline().strip())  # Read the number of elements in the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Read the array elements as integers

    mod = 1000000007  # Set the modulus value
    p = 1  # Initialize 'p' variable to calculate the factorial of all numbers from 2 to 'n'

    # Calculate the factorial of all numbers from 2 to 'n' and store it in 'p' variable
    for i in range(2, n + 1):
        p = p * i % mod

    q = [0] * n  # Initialize a list 'q' of size 'n'
    q[0] = 1  # Initialize the first element of 'q' list with 1

    # Calculate the values of 'q' list using the formula (q[i] = q[i-1] + 1/(i+1) % mod)
    for i in range(1, n):
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod

    ans = 0  # Initialize the answer variable

    # Calculate the answer using the formula ans = sum of (q[i] * a[i] * p) for all i from 0 to n-1
    for i in range(n):
        val = q[i] + q[n - i - 1] - 1  # Calculate the value of 'val' using the formula
        val *= a[i]  # Multiply 'val' with 'a[i]'
        val %= mod  # Modulo the result with the modulus value
        val *= p  # Multiply 'val' with 'p'
        val %= mod  # Modulo the result with the modulus value
        ans += val  # Add the result to the answer
        ans %= mod  # Modulo the answer with the modulus value

    print(ans)  # Print the answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
