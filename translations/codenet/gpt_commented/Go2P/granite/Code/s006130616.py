
import sys

# Read input values for n, m, and x
n, m, x = map(int, input().split())

# Initialize a 2D list to hold skill levels and a list for participant points
a = [list(map(int, input().split())) for _ in range(n)]
p = list(map(int, input().split()))

# Initialize the answer to a large number and other variables for tracking total points and skill validation
ans = 1200001
tot = 0
ok = True
skill = [0] * m

# Iterate through all possible combinations of participants using bit manipulation
for bits in range(1 << n):
    # Reset total points and skill validation flag for the current combination
    tot = 0
    ok = True
    # Initialize a list to accumulate skill levels for the current combination
    skill = [0] * m

    # Check each participant to see if they are included in the current combination
    for i in range(n):
        if (bits >> i) & 1 == 1:
            # Add the points of the selected participant to the total
            tot += p[i]
            # Accumulate the skill levels of the selected participant
            for j in range(m):
                skill[j] += a[i][j]

    # Check if the accumulated skill levels meet the minimum requirement
    for v in skill:
        if v < x:
            ok = False  # If any skill level is below x, mark as not okay
            break

    # If the combination is valid (all skills meet the requirement), update the answer if the total points are lower
    if ok:
        if ans > tot:
            ans = tot

# Output the result: the minimum points needed or -1 if no valid combination was found
if ans!= 1200001:
    print(ans)
else:
    print(-1)

