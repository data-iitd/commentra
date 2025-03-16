def task4(A, B, n):
    # Iterate through a range of possible values for X from -1000 to 1000
    for X in range(-1000, 1001):
        # Check if the equation A * (X ** n) equals B
        if A * (X ** n) == B:
            # If a solution is found, return the value of X
            return X
    # If no solution is found in the range, return a message indicating no solution
    return "No solution"

# Take input from the user and split it into three variables A, B, and n
[A, B, n] = input().split()

# Call the task4 function with the converted integer values of A, B, and n, and print the result
print(task4(int(A), int(B), int(n)))
