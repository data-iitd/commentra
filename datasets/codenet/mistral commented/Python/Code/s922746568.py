
n = int(input())  # Read the number of strings from the user
s = input()       # Read a single string from the user

# Count the number of occurrences of each color in the string
r_cnt = s.count('R')
g_cnt = s.count('G')
b_cnt = s.count('B')

# Calculate the answer based on the number of occurrences of each color
ans = r_cnt * g_cnt * b_cnt

# Check for non-identical triples in the 3D grid formed by the input string
for i in range(n):
    for j in range(n):
        k = i + d  # Increment k by d to check the next element in the string
        if k >= n:  # Break the loop if k goes out of bounds
            break
        # Check if the current triple (s[i], s[j], s[k]) is non-identical
        if s[i] != s[j] and s[j] != s[k] and s[k] != s[i]:
            ans -= 1  # Decrement the answer if a non-identical triple is found

# Print the final answer
print(ans)