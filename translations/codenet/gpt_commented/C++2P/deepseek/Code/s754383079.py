M = 1010

# Declare character arrays to hold the input strings
a = [""] * M
b = [""] * M

# Declare variables for the lengths of the strings and the minimum answer
n = 0
m = 0
ans = M + 10

# Read the first string into array 'a' starting from index 1
a_input = input()
a_input = " " + a_input
n = len(a_input) - 1

# Read the second string into array 'b' starting from index 1
b_input = input()
b_input = " " + b_input
m = len(b_input) - 1

# Iterate over all possible starting positions in 'a' where 'b' can fit
for i in range(1, n - m + 2):
    # Initialize a variable to count the number of mismatches
    sum = 0
    
    # Compare the substring of 'a' with 'b' character by character
    for j in range(1, m + 1):
        # Increment the mismatch count if characters do not match
        if a_input[i + j - 1] != b_input[j]:
            sum += 1
    
    # Update the minimum number of mismatches found
    ans = min(ans, sum)

# Output the minimum number of mismatches
print(ans)

