# Package main is the entry point of the program

# Initialize variables n, m, x for input
n, m, x = map(int, input().split())

# Allocate memory for 2D array a and 1D array p
a = [list(map(int, input().split())) for _ in range(n)]
p = [int(input()) for _ in range(n)]

# Initialize variables ans, tot, and ok
ans = 1200001

# Iterate through all possible combinations of bits
for bits in range(1 << n):
    # Initialize skill array
    skill = [0] * m

    # Calculate total points and update skill array for the current combination of bits
    tot = 0
    ok = True
    for i in range(n):
        # Check if the current bit is set
        if (bits >> i) & 1:
            # Add points from p[i] to total
            tot += p[i]

            # Update skill array for each skill
            for j in range(m):
                skill[j] += a[i][j]

    # Check if the current combination of skills is valid
    for v in skill:
        if v < x:
            ok = False
            break

    # If the current combination is valid, update ans if the total points are less than the current answer
    if ok:
        ans = min(ans, tot)

# Print the answer
print(ans if ans != 1200001 else -1)
