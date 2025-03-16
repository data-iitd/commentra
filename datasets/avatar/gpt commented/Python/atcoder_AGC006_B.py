# Read input values N and X from the user
N, X = [int(_) for _ in input().split()]

# Import permutations from itertools for potential use (not used in the current code)
from itertools import permutations

# Define a function to perform calculations on the input list
def calc(x):
    # Define a helper function to process the list y
    def sub(y, debug=0):
        # If debug mode is on, print the current state of y
        if debug:
            print("D", y)
        # Reduce the list y until it has only one element
        while len(y) > 1:
            # Replace y with the second largest element of every three consecutive elements
            y = [sorted(y[i:i + 3])[1] for i in range(len(y) - 2)]
            # If debug mode is on, print the current state of y
            if debug:
                print("D", y)
        return y
    
    # Call the helper function to process x
    y = sub(x)
    
    # If the final result is 2, perform additional processing
    if y[0] == 2:
        pass  # Placeholder for potential future logic
        sub(x, 1)  # Call sub with debug mode on
        print("=", x)  # Print the original list x
    
    # Return the final processed value
    return y[0]

# Check specific conditions based on the value of X
if X == 1 or X == N * 2 - 1:
    # If X is at the boundaries, print "No"
    print("No")
else:
    # If X is within the valid range, print "Yes"
    print("Yes")
    
    # Handle the case where X is N * 2 - 2
    if X == N * 2 - 2:
        # Create a list xs with specific ranges
        xs = list(range(N - 1, X + 2)) + list(range(1, N - 1))
    else:
        # Create a list ys with specific ranges and then construct xs
        ys = list(range(1, X - 1)) + list(range(X + 3, N * 2))
        xs = ys[:N - 3] + [X + 2, X - 1, X, X + 1] + ys[N - 3:]
    
    # Print each element in the final list xs
    for x in xs:
        print(x)
