
A, B, C, X = map(int, input().split()) # Read the values of A, B, C, and X from the standard input

cnt = 0 # Initialize a counter to count the number of combinations
for a in range(A+1): # Iterate over the possible values of a (0 to A)
    for b in range(B+1): # Iterate over the possible values of b (0 to B)
        for c in range(C+1): # Iterate over the possible values of c (0 to C)
            total = 500*a + 100*b + 50*c # Calculate the total value of the coins
            if total == X: cnt += 1 # If the total equals X, increment the counter

print(cnt) # Output the number of combinations that sum up to X

