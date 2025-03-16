# Read the input values for l and r, which define the range
l, r = [int(x) for x in input().split()]

# Initialize the current value to r and a counter for the number of digits
curr = r
s = 0

# Count the number of digits in the current value (r)
while curr:
    s += 1
    curr //= 10

# Calculate the first power of ten greater than r
first = 10 ** s

# Calculate the second value as half of the first power of ten
second = first // 2

# Initialize the answer variable to store the maximum product found
ans = -1

# Iterate through the possible candidates: l, r, first, and second
for i in [l, r, first, second]:
    # Check if the candidate is within the range [l, r]
    if i >= l and i <= r:
        curr = i
        rev = ''
        
        # Create the reverse number by subtracting each digit from 9
        for k in str(curr):
            rev += str(9 - int(k))
        
        # Update the answer with the maximum product of the current number and its reverse
        ans = max(ans, int(rev) * curr)

# Print the maximum product found
print(ans)
