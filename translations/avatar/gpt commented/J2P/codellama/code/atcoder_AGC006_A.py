import sys

# Define a constant for the maximum size of the arrays
N = 200 + 10
# Array to store the failure function values
f = [0] * (N + 1)
# Array to store the concatenated strings
b = [0] * (N + 1)

# Function to compute the failure function for the KMP algorithm
def get_fail(b, m):
    j = 0 # Initialize j to track the length of the previous longest prefix suffix
    f[0] = f[1] = 0 # Base cases for the failure function

    # Loop through the string to fill the failure function
    for i in range(2, m + 1):
        # Adjust j until we find a match or j becomes 0
        while j > 0 and b[j + 1] != b[i]:
            j = f[j]
        # If there is a match, increment j
        if b[j + 1] == b[i]:
            j += 1
        # Set the failure function value for the current position
        f[i] = j

# Read the length of the strings
n = int(sys.stdin.readline())
# Read the two strings
s1 = sys.stdin.readline().strip()
str = sys.stdin.readline().strip()
cnt = 0

# Concatenate the second string into the character array
for i in range(n):
    b[cnt + 1] = str[i]
    cnt += 1
# Concatenate the first string into the character array
for i in range(n):
    b[cnt + 1] = s1[i]
    cnt += 1

# Compute the failure function for the concatenated strings
get_fail(b, cnt)

# Calculate the length of the longest prefix which is also a suffix
len = min(f[cnt], min(n, n))
# Output the result based on the calculated length
print(2 * n - len)

# 