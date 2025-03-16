# Read input
N, K = map(int, input().split())

# Assign input to a list called S
S = list(input())

# Check character at index K-1 and change it if necessary
if S[K-1] == "A":
  S[K-1] = "a"
elif S[K-1] == "B":
  S[K-1] = "b"
else:
  S[K-1] = "c"

# Join list S back into a single string called ans
ans = "".join(S)

# Print the result
print(ans)