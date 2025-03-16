# Define a constant for the maximum size of the strings
M = 1010

# Declare variables for the lengths of the strings and the minimum answer
a = [''] * M
b = [''] * M
ans = M + 10

# Read the first string into array 'a'
a[1:] = input().strip()  # Read input and strip newline
n = len(a[1:])  # Calculate the length of the first string

# Read the second string into array 'b'
b[1:] = input().strip()  # Read input and strip newline
m = len(b[1:])  # Calculate the length of the second string

# Iterate over all possible starting positions in 'a' where 'b' can fit
for i in range(1, n - m + 2):  # Adjusted range to fit Python's 0-indexing
    # Initialize a variable to count the number of mismatches
    sum_mismatches = 0
    
    # Compare the substring of 'a' with 'b' character by character
    for j in range(1, m + 1):
        # Increment the mismatch count if characters do not match
        if a[i + j - 1] != b[j]:
            sum_mismatches += 1
    
    # Update the minimum number of mismatches found
    ans = min(ans, sum_mismatches)

# Output the minimum number of mismatches
print(ans)

# <END-OF-CODE>
