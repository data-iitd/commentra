
#import sys
#input = sys.stdin.readline

# Read the number of strings N and the length L from the standard input
N, L = map(int, input().split())

# Read N strings from the standard input and store them in the list v
v = []
for _ in range(N):
    v.append(input().rstrip())

# Sort the list v in lexicographical order
v.sort()

# Concatenate and print the sorted strings without spaces
print(''.join(v))

