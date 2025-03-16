
# Read the first string into variable 'a'
a = input()
# Calculate the length of the first string
n = len(a)

# Read the second string into variable 'b'
b = input()
# Calculate the length of the second string
m = len(b)

# Initialize a variable to store the minimum number of mismatches
ans = float('inf')

# Iterate over all possible starting positions in 'a' where 'b' can fit
for i in range(n - m + 1):
    # Initialize a variable to count the number of mismatches
    sum = 0
    # Compare the substring of 'a' with 'b' character by character
    for j in range(m):
        # Increment the mismatch count if characters do not match
        if a[i + j]!= b[j]:
            sum += 1
    # Update the minimum number of mismatches found
    ans = min(ans, sum)

# Output the minimum number of mismatches
print(ans)
