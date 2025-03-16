# Read the number of problems (D) and the maximum score (G) from input
D, G = map(int, input().split())

# Read the problem data, each containing the number of problems and the score for that problem
PC = [tuple(map(int, input().split())) for _ in range(D)]

# Initialize the answer to a large number (infinity)
ans = 10 ** 9

# Iterate through all possible combinations of problems (2^D combinations)
for i in range(2 ** D):
    score = 0  # Initialize the current score
    problem = 0  # Initialize the count of problems solved

    # Calculate the score and number of problems solved for the current combination
    for j in range(D):
        if (i >> j) & 1:  # Check if the j-th problem is included in the combination
            score += 100 * (j + 1) * PC[j][0] + PC[j][1]  # Update score based on the problem's data
            problem += PC[j][0]  # Update the number of problems solved

    # If the current score exceeds the maximum score (G), skip to the next combination
    if score > G:
        continue

    # Calculate the remaining score that can be achieved
    left = G - score

    # Check for each problem that is not included in the current combination
    for j in range(D):
        if (i >> j) & 1:  # Skip if the problem is already included
            continue

        # If the remaining score is greater than the score that can be achieved with this problem, skip
        if left > 100 * (j + 1) * PC[j][0] + PC[j][1]:
            pass
        else:
            # Calculate the minimum number of additional problems needed to reach the remaining score
            tmp = (left + (100 * (j + 1)) - 1) // (100 * (j + 1))
            # Update the answer with the minimum number of problems solved
            ans = min(ans, problem + min(tmp, PC[j][0]))

# Print the minimum number of problems solved to achieve the maximum score
print(ans)
