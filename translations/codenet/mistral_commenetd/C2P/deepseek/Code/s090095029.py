n, m = map(int, input().split())

# Initialize boolean array r0 with all elements set to False
r0 = [False] * n

# Initialize list r1 and counter for its size
r1 = []

# Process each of the m input pairs
for _ in range(m):
    # Read input values for a and b
    a, b = map(int, input().split())

    # Swap a and b if a is greater than b
    if a > b:
        a, b = b, a

    # If a is equal to 1, set the corresponding element in r0 to True
    if a == 1:
        r0[b - 1] = True

    # If b is equal to n, append a - 1 to r1
    if b == n:
        r1.append(a - 1)

# Initialize boolean variable res to False
res = False

# Check if there exists any pair in r1 whose corresponding element in r0 is True
for i in r1:
    # If such a pair is found, set res to True
    if r0[i]:
        res = True

# Output the result based on the value of res
print("POSSIBLE" if res else "IMPOSSIBLE")
