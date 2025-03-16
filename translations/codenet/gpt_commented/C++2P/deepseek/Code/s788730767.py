def nPr(n, r):
    res = 1
    # Calculate nPr using the formula n! / (n - r)!
    for i in range(r):
        res *= (n - i)  # Multiply by (n - i) for r times
    return res  # Return the result


def nCr(n, r):
    # Using the formula nCr = nPr(n, r) / r!
    res = 1
    # Calculate nCr using an iterative approach to avoid large intermediate values
    for i in range(r):
        res *= (n - i)  # Multiply by (n - i)
        res //= (i + 1)  # Divide by (i + 1) to account for r!
    return res  # Return the result as long long


# Input the number of elements and the parity flag
n, p = map(int, input().split())

# Read the array elements and count even and odd numbers
a = list(map(int, input().split()))
b = sum(1 for x in a if x % 2 == 0)  # Count even numbers
c = n - b  # Count odd numbers

# Initialize sums for combinations
bsum = 2 ** b

# Calculate combinations of odd numbers based on the parity flag
if p == 0:
    # If p is 0, count combinations of even counts of odd numbers
    csum = sum(nCr(c, i) for i in range(c + 1) if i % 2 == 0)
else:
    # If p is 1, count combinations of odd counts of odd numbers
    csum = sum(nCr(c, i) for i in range(c + 1) if i % 2 == 1)

# Calculate the final answer as the product of bsum and csum
ans = bsum * csum
# Output the result
print(ans)
