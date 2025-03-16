# Read two integers from input: h (height) and a (height per unit)
h, a = map(int, input().strip().split())

# Calculate the number of complete units of height that can be formed
ans = h // a

# Calculate the remaining height after forming complete units
ama = h % a

# If there is any remaining height, we need one additional unit
if ama != 0:
    ans += 1

# Print the total number of units needed
print(ans)
