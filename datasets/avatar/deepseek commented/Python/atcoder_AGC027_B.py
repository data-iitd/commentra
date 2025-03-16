from itertools import accumulate

# Step 1: Reading Input
# The code reads input values for N, X, and a list of integers A.
# This is done using map(int, open(0).read().split())
N, X, *A = map(int, open(0).read().split())

# Step 2: Accumulating Sums
# The code uses accumulate(A) to create a list of accumulated sums of A.
# This is stored in the variable S.
S = list(accumulate(A))

# Step 3: Initializing Answer
# The variable ans is initialized to infinity (float("inf")).
ans = float("inf")

# Step 4: Calculating Energy
# The code iterates over the accumulated sums S with an index k starting from 1.
# For each k, it calculates the energy E using the formula k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k)).
# It then updates ans with the minimum value between the current ans and the calculated E.
for k, s in enumerate(S, 1):
    E = k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k))
    ans = min(ans, E)

# Step 5: Final Calculation
# After the loop, the code calculates the final result by adding ans to N * X + 5 * S[-1] and prints it.
print(ans + N * X + 5 * S[-1])
