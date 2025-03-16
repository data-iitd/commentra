# Step 2: Define constant for string length
M = 1010  # Maximum length for strings

# Step 2: Define variables to store input strings
a = input().strip()  # Read input string a
b = input().strip()  # Read input string b

n = len(a)  # Length of string a
m = len(b)  # Length of string b
ans = M + 10  # Initialize minimum differences

# Step 4: Calculate the minimum number of differences
for i in range(n - m + 1):  # Iterate over possible starting positions
    sum_diff = 0  # Initialize sum of differences for current starting position
    for j in range(m):  # Compare each character of b with corresponding character in a
        if a[i + j] != b[j]:  # Check if characters are different
            sum_diff += 1  # Increment sum if characters are different
    ans = min(ans, sum_diff)  # Update minimum differences

# Step 5: Output the result
print(ans)  # Print the minimum number of differences

# <END-OF-CODE>
