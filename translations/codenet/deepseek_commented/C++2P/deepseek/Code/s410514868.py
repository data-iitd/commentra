import sys

# Reading the input values for n and k, and the string s
n, k = map(int, sys.stdin.readline().split())
s = sys.stdin.readline().strip()

# Initializing L with the first character of s, and ans, cnt to zero
L = s[0]
ans = 0
cnt = 0
ans2 = 0

# Loop through the string starting from the second character
for i in range(1, n):
    if L == s[i]:
        cnt += 1
    else:
        # Update L to the new character, add cnt to ans, increment ans2, and reset cnt
        ans += cnt
        ans2 += 1
        L = s[i]
        cnt = 0

# Add the final count to ans and increment ans2
ans += cnt
ans2 += 1

# Calculate the output as ans + min(2*k, ans2-1) and print it
print(ans + min(2 * k, ans2 - 1))
