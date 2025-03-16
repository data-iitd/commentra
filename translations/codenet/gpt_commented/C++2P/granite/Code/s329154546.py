
# Read the number of strings (N) and the length of each string (L)
N, L = map(int, input().split())

# Declare a list to hold the strings
S = []

# Input the strings from the user
for _ in range(N):
    S.append(input())

# Sort the list of strings in lexicographical order
S.sort()

# Output the sorted strings
for s in S:
    print(s)

# Print a newline at the end of the output
print()

