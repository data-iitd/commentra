# Read the integer input for the length of the string
n = int(input())

# Read the string input consisting of characters 'R', 'G', and 'B'
s = input()

# Count the occurrences of each character in the string
r_cnt = s.count('R')  # Count of 'R'
g_cnt = s.count('G')  # Count of 'G'
b_cnt = s.count('B')  # Count of 'B'

# Calculate the initial answer as the product of the counts of 'R', 'G', and 'B'
ans = r_cnt * g_cnt * b_cnt

# Iterate through all possible combinations of indices in the string
for i in range(n):
    for d in range(n):
        j = i + d  # Calculate the second index based on the first index and distance d
        k = j + d  # Calculate the third index based on the second index and distance d
        
        # Break the loop if the third index exceeds the length of the string
        if k >= n:
            break 
        
        # Check if the characters at the three indices are all different
        if s[i] != s[j] and s[j] != s[k] and s[k] != s[i]:
            # If they are all different, decrement the answer by 1
            ans -= 1

# Print the final answer
print(ans)
