# Input the number of elements and the parity flag
n, p = map(int, input().split())

# Read the array elements and count even and odd numbers
a = list(map(int, input().split()))
b = 0
c = 0
for i in range(n):
    if a[i] % 2 == 0:
        b += 1
    else:
        c += 1

# Initialize sums for combinations
bsum = 0
csum = 0
# Calculate the total subsets of even numbers (2^b)
bsum = 2 ** b

# Calculate combinations of odd numbers based on the parity flag
if p == 0:
    # If p is 0, count combinations of even counts of odd numbers
    for i in range(c + 1):
        if i % 2 == 0:
            csum += nCr(c, i)
else:
    # If p is 1, count combinations of odd counts of odd numbers
    for i in range(c + 1):
        if i % 2 == 1:
            csum += nCr(c, i)

# Calculate the final answer as the product of bsum and csum
ans = bsum * csum
# Output the result
print(ans)

