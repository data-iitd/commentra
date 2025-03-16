
# Step 1: Import necessary modules
import sys

# Step 2: Define constant for string length
M = 1010  # Step 2: Define constant for string length

# Step 3: Read input strings
a = input()  # Read and store the input string a
b = input()  # Read and store the input string b
n = len(a)  # Calculate the length of string a
m = len(b)  # Calculate the length of string b

# Step 4: Calculate the minimum number of differences
ans = M + 10  # Initialize minimum differences
for i in range(n - m + 1):  # Iterate over possible starting positions
    sum = 0  # Initialize sum of differences for current starting position
    for j in range(m):  # Compare each character of b with corresponding character in a
        if a[i + j]!= b[j]:  # Check if characters are different
            sum += 1  # Increment sum if characters are different
    ans = min(ans, sum)  # Update minimum differences

# Step 5: Output the result
print(ans)  # Print the minimum number of differences

# 