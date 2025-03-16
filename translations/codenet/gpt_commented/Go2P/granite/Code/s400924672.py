
# Read input values for r, D, and x from the user
r, D, x = map(int, input().split())

# Loop to perform calculations and print results for 10 iterations
for i in range(1, 11):
    # Calculate and print the result of the formula r*x - D
    print(r*x - D)
    
    # Update x for the next iteration using the formula r*x - D
    x = r*x - D

