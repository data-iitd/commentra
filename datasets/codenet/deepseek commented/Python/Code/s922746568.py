
n=int(input())
s=input()

# Count the number of 'R', 'G', and 'B' characters in the string
r_cnt = s.count('R')
g_cnt = s.count('G')
b_cnt = s.count('B')

# Calculate the initial answer as the product of the counts of 'R', 'G', and 'B'
ans = r_cnt * g_cnt * b_cnt

# Iterate over possible triplets in the string
for i in range(n):
    for d in range(n):
        j = i + d
        k = j + d
        if k >= n:
            break 
        # Check if the characters in the triplet are all different
        if s[i] != s[j] and s[j] != s[k] and s[k] != s[i]:
            # Decrease the answer by 1 if the characters are all different
            ans -= 1
print(ans)

