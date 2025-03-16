# Read input strings S and T from the user
S = input()
T = input()

# Get the lengths of the input strings S and T
N = len(S)
M = len(T)

# Initialize the answer with the maximum possible value, which is the length of T
ans = M

# Iterate through all possible starting positions in S where T could fit
for i in range(N - M + 1):
    # Extract a substring of S of the same length as T
    S_2 = S[i:i + M]
    
    # Initialize a counter for the number of differing characters
    cnt = 0
    
    # Compare each character of T with the corresponding character in the substring S_2
    for j in range(M):
        if T[j] != S_2[j]:
            cnt += 1  # Increment the counter if characters do not match
    
    # Update the answer with the minimum number of differing characters found so far
    ans = min(ans, cnt)

# Print the minimum number of differing characters between T and any substring of S
print(ans)
