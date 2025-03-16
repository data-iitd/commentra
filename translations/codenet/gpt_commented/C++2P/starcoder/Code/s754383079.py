
# Define a constant for the maximum size of the strings
M = 1010

# Declare character arrays to hold the input strings
a = [None] * M
b = [None] * M

# Declare variables for the lengths of the strings and the minimum answer
n, m, ans = M+10, M+10, M+10

# Read the first string into array 'a' starting from index 1
a[1] = input()
# Calculate the length of the first string
n = len(a[1])

# Read the second string into array 'b' starting from index 1
b[1] = input()
# Calculate the length of the second string
m = len(b[1])

# Iterate over all possible starting positions in 'a' where 'b' can fit
for i in range(1, n - m + 1):
    # Initialize a variable to count the number of mismatches
    sum = 0

    # Compare the substring of 'a' with 'b' character by character
    for j in range(1, m + 1):
        # Increment the mismatch count if characters do not match
        if a[i + j - 1]!= b[j]:
            sum += 1

    # Update the minimum number of mismatches found
    ans = min(ans, sum)

# Output the minimum number of mismatches
print(ans)

