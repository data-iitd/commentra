# Function to find a number X raised to the power n such that A * X^n equals B
def task4(A, B, n):

    # Iterate through all possible values of X from -1000 to 1000
    for X in range(-1000, 1001):

        # Check if the condition A * X^n equals B is satisfied
        if A * (X ** n) == B:

            # If the condition is satisfied, return the value of X
            return X

    # If no solution is found, return a message indicating that
    return "No solution"

# Get input values of A, B, and n from the user
[A, B, n] = input().split()

# Convert input strings to integers
[A, B, n] = [int(i) for i in [A, B, n]]

# Call the function and print the result
print(task4(A, B, n))
