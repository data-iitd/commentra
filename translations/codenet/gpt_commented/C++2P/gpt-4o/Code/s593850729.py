# Declare variables to hold the maximum counts of each denomination and the target amount
A, B, C, X = map(int, input().split())

# Initialize a counter to keep track of the number of combinations that sum to X
cnt = 0

# Iterate through all possible counts of 500 yen coins (from 0 to A)
for a in range(A + 1): 
    # Iterate through all possible counts of 100 yen coins (from 0 to B)
    for b in range(B + 1):
        # Iterate through all possible counts of 50 yen coins (from 0 to C)
        for c in range(C + 1):
            # Calculate the total amount using the current counts of coins
            total = 500 * a + 100 * b + 50 * c
            
            # Check if the calculated total matches the target amount X
            if total == X: 
                # If it matches, increment the counter
                cnt += 1

# Output the total number of combinations that sum to X
print(cnt)

# <END-OF-CODE>
