from itertools import combinations_with_replacement
import sys

# Function to read a line of input and convert it to a list of integers
def LI(): return map(int, sys.stdin.readline().rstrip().split())

# Read the values of N (number of elements), M (range of values), and Q (number of queries)
N, M, Q = LI()

# Initialize a list to store the query groups
Q_groups = []
# Read each query and store it in the Q_groups list
for _ in range(Q):
    Q_groups.append([*LI()])

# Initialize a variable to keep track of the maximum score found
max_score = 0

# Generate all combinations of N elements with replacement from the range 1 to M
for p in combinations_with_replacement(range(1, M + 1), r=N):
    # Initialize a temporary score for the current combination
    temp_score = 0
    # Evaluate each query against the current combination
    for q in Q_groups:
        # Check if the condition specified in the query is satisfied
        if p[q[1] - 1] - p[q[0] - 1] == q[2]:
            # If the condition is met, add the score from the query to the temporary score
            temp_score += q[3]
    # Update the maximum score if the temporary score is greater
    max_score = max(max_score, temp_score)

# Output the maximum score found
print(max_score)
