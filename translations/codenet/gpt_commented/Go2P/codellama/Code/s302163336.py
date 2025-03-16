
# Initialize a scanner to read input from standard input
sc = input().split()

# Read the number of elements (n) and the number of comparisons (m)
n, m = int(sc[0]), int(sc[1])

# Create a list to hold the heights and a list to track which elements are "good"
h = [int(sc[i]) for i in range(2, 2 + n)]
good = [True] * n

# Read the heights and initialize the good list to true
for i in range(n):
    good[i] = True

# Process each comparison
for i in range(m):
    ai, bi = int(sc[2 + n + i * 2]), int(sc[2 + n + i * 2 + 1])

    # Compare the heights and update the good list accordingly
    if h[ai] > h[bi]:
        good[bi] = False
    elif h[ai] < h[bi]:
        good[ai] = False
    else:
        # If heights are equal, mark both as not "good"
        good[ai] = False
        good[bi] = False

# Count the number of "good" elements
ans = 0
for i in range(n):
    if good[i]:
        ans += 1

# Print the result: the number of "good" elements
print(ans)

