
# Declare variables for the number of red, green, blue items and the total number of items
r, g, b, n = map(int, input().split())

# Initialize the answer counter to zero
ans = 0

# Iterate over the possible counts of red items (i)
for i in range(n // r + 1):
    # Iterate over the possible counts of green items (j)
    for j in range(n // g + 1):
        # Calculate the remaining items after selecting i red and j green items
        num = n - r * i - g * j

        # Check if the remaining items can be exactly filled with blue items
        if num >= 0 and num % b == 0:
            # If valid, increment the answer counter
            ans += 1

# Output the total number of valid combinations found
print(ans)

