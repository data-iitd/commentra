
N, L = map(int, input().split())
# Read the number of strings (N) and the length of each string (L)

S = [input().rstrip() for _ in range(N)]
# Read N strings of length L and store them in the list S

print(''.join(sorted(S)))
# Sort the list S alphabetically and print the sorted list joined as a single string

