
S = input()
T = input()

# Read the input strings S and T

N = len(S)
M = len(T)
# Calculate the lengths of S and T and store them in N and M

ans = M
# Initialize ans with the length of T, representing the minimum number of changes needed

for i in range(N-M+1):
    S_2 = S[i:i+M]
    cnt = 0
    # For each starting position, extract a substring of length M from S
    # Initialize a counter to count mismatches
    
    for j in range(M):
        if T[j] != S_2[j]:
            cnt += 1
    # Compare each character of T with the corresponding character in S_2
    # Increment the counter for each mismatch
    
    ans = min(ans, cnt)
    # Update ans with the minimum number of mismatches found

print(ans)
# Print the final result, which is the minimum number of changes needed