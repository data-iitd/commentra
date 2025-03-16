
# Python code

# Read input values for l, r, and d
l = int(input())
r = int(input())
d = int(input())

# Count the multiples of d in the range [l, r]
ans = 0
for i in range(l, r + 1):
    if i % d == 0:
        ans += 1

# Output the result
print(ans)

