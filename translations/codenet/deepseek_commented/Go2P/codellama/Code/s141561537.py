
# Declare variables to store input and result
a, b, c, x, sum = 0, 0, 0, 0, 0

# Read input values for a, b, c, and x
a, b, c, x = map(int, input().split())

# Nested loops to iterate through all combinations of coins
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if 500*i + 100*j + 50*k == x:
                sum += 1

# Output the number of combinations that meet the condition
print(sum)

