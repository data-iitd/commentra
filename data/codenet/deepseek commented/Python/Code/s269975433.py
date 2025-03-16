from itertools import combinations_with_replacement
import sys

def LI(): return map(int, sys.stdin.readline().rstrip().split())

# Reading Input: The function LI() is defined to read input from sys.stdin and return a list of integers.
N, M, Q = LI()

# Initialization: The variables N, M, and Q are read using the LI() function. Q_groups is initialized to store the conditions.
Q_groups = []
for _ in range(Q):
    # Reading Conditions: The code enters a loop to read Q conditions, each consisting of four integers, and appends them to Q_groups.
    Q_groups.append([*LI()])

max_score = 0
for p in combinations_with_replacement(range(1, M + 1), r=N):
    # Finding Combinations: The code uses combinations_with_replacement from itertools to generate combinations of numbers from 1 to M, taken N at a time.
    temp_score = 0
    for q in Q_groups:
        # Calculating Scores: For each combination p, the code calculates a temporary score by iterating over each condition in Q_groups.
        if p[q[1] - 1] - p[q[0] - 1] == q[2]:
            temp_score += q[3]
    max_score = max(max_score, temp_score)

# Updating Maximum Score: The maximum score is updated by comparing it with the temporary score for each combination.
# Output: Finally, the maximum score is printed.
print(max_score)