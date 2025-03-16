def main():
    # Read the number of elements
    n = int(input())

    # Initialize a list to store the input numbers and a dictionary to store the maximum prime factors
    as_list = [0] * n
    ps = {}

    # Read each number and perform prime factorization
    for i in range(n):
        as_list[i] = int(input())

        # Get the prime factors of the current number
        ns = prime_factorize(as_list[i])
        # Update the maximum count of each prime factor found
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)

    # Calculate the product of the maximum prime factors raised to their respective powers
    x = 1
    for k, v in ps.items():
        for i in range(1, v + 1):
            x = mul(x, k)

    # Calculate the final answer by summing the results of x divided by each input number
    ans = 0
    for i in range(n):
        ans = add(ans, div(x, as_list[i]))

    # Print the final answer
    print(ans)

# Function to return the maximum of two integers
def max(a, b):
    return a if a > b else b

# Function to perform prime factorization of a number
def prime_factorize(n):
    res = {}
    # Check for factors from 2 up to the square root of n
    for i in range(2, int(n**0.5) + 1):
        # While i is a factor of n, divide n by i and count the occurrences
        while n % i == 0:
            n //= i
            res[i] = res.get(i, 0) + 1
    # If n is still greater than 1, it is a prime factor itself
    if n > 1:
        res[n] = res.get(n, 0) + 1
    return res

# Define a constant for the modulo operation
mod = 1000000007

# Function to compute n raised to the power of k under modulo
def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k - 1) * n % mod
    else:
        t = pow(n, k // 2)
        return t * t % mod

# Function to add two integers under modulo
def add(a, b):
    return (a + b) % mod

# Function to subtract two integers under modulo
def sub(a, b):
    return (a + mod - b) % mod

# Function to multiply two integers under modulo
def mul(a, b):
    return a % mod * b % mod % mod

# Function to divide two integers under modulo using modular multiplicative inverse
def div(a, b):
    return mul(a, pow(b, mod - 2))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
