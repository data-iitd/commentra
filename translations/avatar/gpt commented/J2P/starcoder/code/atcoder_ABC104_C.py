import sys

# Define a constant for infinity (a large number)
INF = 100000

# Read the number of problems D and the goal score G
D = int(sys.stdin.readline())
G = int(sys.stdin.readline())

# Arrays to store the number of problems and their corresponding scores
p = [0] * D # p[i] = number of problems for the i-th problem set
c = [0] * D # c[i] = additional score for the i-th problem set

# Read the number of problems and additional scores for each problem set
for i in range(D):
    p[i], c[i] = map(int, sys.stdin.readline().split())

# Initialize the minimum number of problems solved to infinity
min = INF

# Iterate through all possible combinations of problem sets using bit masking
for bit in range(1 << D):
    score = 0 # Total score achieved with the current combination
    solve_num = 0 # Total number of problems solved with the current combination

    # Calculate the score and number of problems solved for the current combination
    for i in range(D):
        if (bit & (1 << i))!= 0: # Check if the i-th problem set is included
            score += 100 * (i + 1) * p[i] + c[i] # Update score
            solve_num += p[i] # Update number of problems solved

    # If the current score is less than the goal score G
    if score < G:
        for i in range(D - 1, -1, -1): # Iterate through problem sets in reverse
            if (bit & (1 << i)) == 0: # Check if the i-th problem set is not included
                # Attempt to solve additional problems from this set
                for j in range(p[i] - 1):
                    score += 100 * (i + 1) # Increase score by the value of the problem
                    solve_num += 1 # Increment the number of problems solved
                    if score >= G: # If the score meets or exceeds the goal
                        break

    # If the score meets or exceeds the goal, update the minimum number of problems solved
    if score >= G:
        min = min(min, solve_num) # Update min if a better solution is found

# Output the minimum number of problems solved to achieve the goal score
print(min)

# 