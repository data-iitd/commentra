# Declare variables for input
n, k, x, y = map(int, input().split())

# Initialize sum to accumulate total cost
sum = 0

# Loop through each item from 1 to n
for i in range(1, n+1):
    # If the current item index exceeds k, add cost y; otherwise, add cost x
    if i > k:
        sum += y
    else:
        sum += x

# Output the total calculated cost
print(sum)

