
# ABC 152-D
# 2020.1.19 bal4u

# Fast input function to read a character from standard input
gc = lambda: input()

# Function to read a non-negative integer from input
def in():
    n = 0
    # Loop to construct the integer from characters until a non-digit is encountered
    for c in gc():
        n = 10 * n + int(c)
    return n

# Arrays to store frequency counts for two different calculations
f1 = [0] * 100
f2 = [0] * 100

# Function to calculate frequency counts based on the input number
def calc(n):
    k = n % 10
    # Reduce n to its first digit by continuously dividing by 10
    while n >= 10: n //= 10
    # Update frequency counts for combinations of first and last digits
    f1[10*k + n] += 1
    f2[n*10 + k] += 1

N = in()
# Process each number from N down to 1
while N: calc(N); N -= 1

ans = 0
# Calculate the final answer by summing the products of corresponding frequencies
for i in range(100): ans += f1[i] * f2[i]
# Output the final answer
print(ans)

