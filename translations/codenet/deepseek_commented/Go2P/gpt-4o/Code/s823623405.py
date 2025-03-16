def main():
    n = int(input())  # Read the number of elements
    as_ = list(map(int, input().split()))  # Read each element of the array

    ps = {}
    for num in as_:
        ns = prime_factorize(num)  # Prime factorize the current element
        for k, v in ns.items():
            ps[k] = max(ps.get(k, 0), v)  # Update the map with the prime factors and their powers

    x = 1
    for k, v in ps.items():
        for i in range(1, v + 1):
            x = mul(x, k)  # Calculate the LCM by multiplying the prime factors with their powers

    ans = 0
    for num in as_:
        ans = add(ans, div(x, num))  # Calculate the sum of modular inverses
    print(ans)  # Print the final answer

def max(a, b):
    return a if a > b else b

def prime_factorize(n):
    res = {}
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            n //= i
            res[i] = res.get(i, 0) + 1
    if n != 1:
        res[n] = res.get(n, 0) + 1
    return res

mod = 1000000007

def pow(n, k):
    if k == 0:
        return 1
    elif k % 2 == 1:
        return pow(n, k - 1) * n % mod
    else:
        t = pow(n, k // 2)
        return t * t % mod

def add(a, b):
    return (a + b) % mod

def sub(a, b):
    return (a + mod - b) % mod

def mul(a, b):
    return a % mod * b % mod % mod

def div(a, b):
    return mul(a, pow(b, mod - 2))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
