
# Initialize a list to hold m integers
a = []

# Read m integers into the list a
for i in range(m):
    a.append(int(input()))

# Calculate the sum of integers in the list a
sum = 0
for i in range(m):
    sum += a[i]

# Check if the sum of integers exceeds n
if sum > n:
    # Print -1 if the sum exceeds n and exit
    print(-1)
    exit()

# Print the difference between n and the sum if it's within bounds
print(n - sum)

