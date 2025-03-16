# Vector to store strings and variables to store N and L
v = []

# Read the number of strings N and the length L from the standard input
N, L = map(int, input().split())

# Read N strings from the standard input and store them in the vector v
for _ in range(N):
    s = input()
    v.append(s)

# Sort the vector v in lexicographical order
v.sort()

# Concatenate and print the sorted strings without spaces
print(''.join(v))
