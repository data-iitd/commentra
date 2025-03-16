import sys

# Read the number of strings from the standard input
n = int(input().strip())

# Initialize the count of each character to 1
cnt = [1] * 26
s = list(input().strip())

# Update the count vector accordingly
for i in range(n):
    cnt[ord(s[i]) - ord('a')] += 1

# Calculate the answer using the count vector
ans = 1
for i in range(26):
    ans *= cnt[i]

# Calculate the final answer by subtracting 1 from the initial answer
ans -= 1

# Print the final answer to the standard output
print(ans)

