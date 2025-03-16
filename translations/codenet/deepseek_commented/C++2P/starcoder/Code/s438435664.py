
# Read two integers n and k
n, k = map(int, input().split())

# Initialize the sum
sum = 0

# Iterate over possible values of b
for b in range(1, n + 1):
    # Calculate the count and remainder
    cnt = (n + 1) // b
    md = (n + 1) % b

    # Update the sum based on the conditions involving k
    sum += cnt * max((b - k), 0) + max((md - k), 0)

    # Adjust the sum if k is 0
    if k == 0:
        sum -= 1

# Print the computed sum
print(sum)

