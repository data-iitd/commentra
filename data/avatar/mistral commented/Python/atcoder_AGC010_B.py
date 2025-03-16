# Take input from the user
n, a = int(input()), list(map(int, input().split()))

# Check if the sum of the elements in the list is divisible by the formula
if sum(a) % (n * (n + 1) // 2):
    print("NO")
    exit()

# Calculate the average of the elements in the list
k = sum(a) / (n * (n + 1) // 2)

# Add the first element to the end of the list for simplification
a += [a[0]]

# Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
if sum([(k - i + j) % n for i, j in zip(a[1:], a)]) or sum([(k - i + j) / n >= 0 for i, j in zip(a[1:], a)]) != n:
    print("NO")
    exit()

# If all checks pass, print YES
print("YES")
