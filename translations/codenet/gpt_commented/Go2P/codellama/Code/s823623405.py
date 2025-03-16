
# Read the number of elements
n = int(input())

# Initialize a list to store the input numbers and a dictionary to store the maximum prime factors
as = [0] * n
ps = {}

# Read each number and perform prime factorization
for i in range(n):
    as[i] = int(input())
    # Get the prime factors of the current number
    ns = primeFactorize(as[i])
    # Update the maximum count of each prime factor found
    for k, v in ns.items():
        ps[k] = max(ps.get(k, 0), v)

# Calculate the product of the maximum prime factors raised to their respective powers
x = 1
for k, v in ps.items():
    for i in range(1, v+1):
        x = (x * k) % mod

# Calculate the final answer by summing the results of x divided by each input number
ans = 0
for i in range(n):
    ans = (ans + (x // as[i])) % mod

# Print the final answer
print(ans)


