def main():
    import sys
    from collections import defaultdict

    # Initialize variables
    n = int(sys.stdin.readline().strip())  # Read the number of integers from the standard input
    as_ = list(map(int, sys.stdin.readline().strip().split()))  # Read the input integers
    ps = defaultdict(int)  # Create a dictionary to store the prime factors and their powers

    # Read the input integers and calculate their prime factors
    for num in as_:
        ns = prime_factorize(num)  # Calculate the prime factors and their powers of the current integer
        for k, v in ns.items():  # Iterate through the dictionary to update the powers of the prime factors
            ps[k] = max(ps[k], v)  # Update the power of the current prime factor if it's greater

    # Calculate the answer
    x = 1  # Initialize a variable to store the product of prime factors
    for k, v in ps.items():  # Iterate through the dictionary to calculate the product of prime factors
        for i in range(1, v + 1):  # Calculate the power of the prime factor
            x = mul(x, k)  # Multiply the current product with the prime factor

    ans = 0  # Initialize a variable to store the answer
    for num in as_:  # Iterate through the list to calculate the answer
        ans = add(ans, div(x, num))  # Calculate the difference between the current product and the current integer, and add it to the answer

    print(ans)  # Print the answer

def max(a, b):
    # Return the maximum of two integers
    return a if a > b else b

def prime_factorize(n):
    # Calculate the prime factors and their powers of a given integer
    res = defaultdict(int)
    for i in range(2, int(n**0.5) + 1):  # Iterate through the possible prime factors
        while n % i == 0:  # If the current number is divisible by the current prime factor
            n //= i  # Divide the current number by the prime factor
            res[i] += 1  # Increment the power of the prime factor
    if n != 1:  # If the number is not equal to 1, it means that it has a prime factor greater than 1
        res[n] += 1  # Increment the power of the last prime factor
    return res

mod = 1000000007

def pow(n, k):
    # Calculate n raised to the power of k modulo mod
    if k == 0:
        return 1
    elif k % 2 == 1:
        return (pow(n, k - 1) * n) % mod
    else:
        t = pow(n, k // 2)
        return (t * t) % mod

def add(a, b):
    # Return the sum of two integers modulo mod
    return (a + b) % mod

def sub(a, b):
    # Return the difference of two integers modulo mod
    return (a + mod - b) % mod

def mul(a, b):
    # Return the product of two integers modulo mod
    return (a % mod * b % mod) % mod

def div(a, b):
    # Return the quotient of a and b modulo mod
    return mul(a, pow(b, mod - 2))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
