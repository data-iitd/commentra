# Read the number of different types of problems (d) and the target score (g)
d, g = list(map(int, input().split()))

# Read the problem count and score for each type of problem into a list
pc = [list(map(int, input().split())) for _ in range(d)]

# Initialize the minimum number of problems needed to infinity
ans = float("inf")

# Iterate over all possible combinations of problems using bit manipulation
for bit in range(1 << d):
    count = 0  # Initialize the count of problems solved
    sum = 0    # Initialize the total score achieved
    nokori = set(range(1, d + 1))  # Set of remaining problem types

    # Check each problem type to see if it is included in the current combination
    for i in range(d):
        if bit & (1 << i):  # If the i-th problem type is included
            # Update the total score and count of problems solved
            sum += pc[i][0] * (i + 1) * 100 + pc[i][1]
            count += pc[i][0]
            nokori.discard(i + 1)  # Remove this problem type from the remaining set
    
    # If the current score is less than the target score
    if sum < g:
        # Get the maximum remaining problem type
        use = max(nokori)
        # Calculate how many more problems of this type are needed to reach the target score
        n = min(pc[use-1][0], -(-(g - sum) // (use * 100)))
        count += n  # Update the count of problems solved
        sum += n * use * 100  # Update the total score with the additional problems

    # If the total score meets or exceeds the target score
    if sum >= g:
        # Update the minimum number of problems needed
        ans = min(ans, count)

# Print the minimum number of problems needed to achieve at least the target score
print(ans)
