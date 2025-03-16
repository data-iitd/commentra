D, G = map(int, input().split())  # Reading the number of problems and target score
PC = [tuple(map(int, input().split())) for _ in range(D)]  # Reading the number of problems and bonus points for each problem
ans = 10 ** 9  # Initializing the answer to a large number

# Iterating over all possible combinations of problems using a bitmask approach
for i in range(2 ** D):
    score = 0  # Initializing the current score
    problem = 0  # Initializing the number of problems solved
    
    # Calculating the total score and the number of problems solved for the current combination
    for j in range(D):
        if (i >> j) & 1:
            score += 100 * (j + 1) * PC[j][0] + PC[j][1]
            problem += PC[j][0]
    
    # If the total score is greater than or equal to the target score, skip to the next combination
    if score >= G:
        continue
    
    # Calculating the remaining score needed to reach or exceed the target score
    left = G - score
    
    # Checking if the remaining score can be achieved by solving additional problems
    for j in range(D):
        if (i >> j) & 1:
            continue
        if left > 100 * (j + 1) * PC[j][0] + PC[j][1]:
            pass  # If the remaining score is not enough, continue to the next problem
        else:
            tmp = (left + (100 * (j + 1)) - 1) // (100 * (j + 1))  # Calculating the number of problems needed
            ans = min(ans, problem + min(tmp, PC[j][0]))  # Updating the minimum number of problems solved

# Printing the minimum number of problems solved to achieve the target score
print(ans)
