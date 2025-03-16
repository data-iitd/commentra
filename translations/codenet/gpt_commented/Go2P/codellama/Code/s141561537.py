
# Declare variables for the number of coins of each type and the target amount
a = 0
b = 0
c = 0
x = 0
sum = 0

# Read input values for the number of coins of each type (a, b, c) and the target amount (x)
a, b, c, x = map(int, input().split())

# Initialize a loop to iterate through all possible counts of 500 yen coins
for i in range(a+1):
    # Nested loop to iterate through all possible counts of 100 yen coins
    for j in range(b+1):
        # Innermost loop to iterate through all possible counts of 50 yen coins
        for k in range(c+1):
            # Check if the current combination of coins equals the target amount (x)
            if 500*i+100*j+50*k == x:
                # If the combination matches, increment the sum of valid combinations
                sum += 1

# Output the total number of combinations that sum up to the target amount
print(sum)

