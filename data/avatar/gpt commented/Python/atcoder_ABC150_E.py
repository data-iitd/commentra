# Define the modulo constant
mod = 10 ** 9 + 7

# Read the number of elements
n = int(input())

# Read the list of integers and convert them to a list of integers
c = list(map(int, input().split()))

# Sort the list in descending order
c.sort(reverse=True)

# Calculate the value of b as 2^(2*n - 2) modulo mod
b = pow(2, 2 * n - 2, mod)

# Calculate the value of a as 2 * b modulo mod
a = 2 * b % mod

# Initialize the answer variable
ans = 0

# Iterate through the sorted list and calculate the answer
for i in range(n):
    # Update the answer by adding the product of the current element and (a + i * b)
    ans += c[i] * (a + i * b)
    # Ensure the answer remains within the modulo
    ans %= mod

# Print the final result
print(ans)
