# Take two strings, S and T, as input
S = input()
T = input()

# Calculate the lengths of the strings, N for S and M for T
N = len(S)
M = len(T)

# Initialize an answer variable ans with the value of M
ans = M

# Use a for loop to iterate through all possible substrings of S that have the same length as T
for i in range(N-M+1):
    # Initialize a counter variable cnt to 0
    cnt = 0
    
    # Use another for loop to compare each character in the substring with the corresponding character in T
    for j in range(M):
        # If the characters do not match, increment the counter variable cnt
        if T[j] != S[i+j]:
            cnt += 1
    
    # Update the answer variable ans with the minimum value of the counter variable cnt and the current value of ans
    ans = min(ans, cnt)

# Print the minimum number of mismatches found between S and T
print(ans)
