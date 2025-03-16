# Read two integers N and L from input, where N is the number of strings and L is the length of each string
N, L = map(int, input().split())

# Read N strings from input, stripping any trailing whitespace from each string
S = [input().rstrip() for _ in range(N)]

# Sort the list of strings S and join them into a single string, then print the result
print(''.join(sorted(S)))
