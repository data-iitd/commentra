#######
# Code
#######

# Define input variables
D, G = map(int, input().split())

# Initialize list of problems with their respective capacities
PC = [tuple(map(int, input().split())) for _ in range(D)]

# Initialize variables for current iteration
ans = 10 ** 9

# Loop through all possible combinations of problems
for i in range(2 ** D):
    # Initialize variables for current combination
    score = 0
    problem = 0

    # Calculate score for current combination
    for j in range(D):
        # If problem j is included in current combination
        if (i >> j) & 1:
            # Add score for problem j to the total score
            score += 100 * (j + 1) * PC[j][0] + PC[j][1]
            # Add capacity of problem j to the total problem
            problem += PC[j][0]

    # If score for current combination is greater than goal G, skip to next combination
    if score > G:
        continue

    # Calculate remaining capacity to be covered
    left = G - score

    # Loop through all problems and check if they can be included in the solution
    for j in range(D):
        # If problem j is already included in current combination, skip it
        if (i >> j) & 1:
            continue

        # Check if including problem j can cover the remaining capacity
        if left > 100 * (j + 1) * PC[j][0] + PC[j][1]:
            pass
        else:
            # Calculate the number of instances of problem j that can be included
            tmp = (left + (100 * (j + 1) - 1) // (100 * (j + 1)))
            # Update the answer if including more instances of problem j results in a better solution
            ans = min(ans, problem + min(tmp, PC[j][0]))

# Print the answer
print(ans)
