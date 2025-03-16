# Import the itertools module and specifically the accumulate function
from itertools import accumulate

# Define input variables
N, X, *A = map(int, open(0).read().split())

# Create a new list S by applying the accumulate function to the list A
S = list(accumulate(A))

# Initialize a variable ans with a large value
ans = float("inf")

# Iterate through each element s in the list S
for k, s in enumerate(S, 1):
    # Calculate the energy consumption E for the current index k
    E = k * X + 2 * sum(S[j] for j in range(N - 2*k - 1, -1, -k))

    # Update the minimum energy consumption ans if the current energy consumption E is smaller
    ans = min(ans, E)

# Print the result
print(ans + N * X + 5 * S[-1])
