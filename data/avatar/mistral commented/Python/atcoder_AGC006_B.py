# Define input variables
N, X = [int(_) for _ in input().split()]
# Comment: Read input values N and X from the standard input

# Import itertools module for generating permutations
from itertools import permutations
# Comment: Import itertools module and specifically the permutations function

def calc(x):
# Define a function calc that takes an integer x as an argument

    def sub(y, debug=0):
    # Define a nested function sub that takes an integer y and an optional debug argument

        if debug:
            print("D", y)
        # If debug is set to True, print the intermediate values of y

        while len(y) > 1:
            y = [sorted(y[i:i+3])[1] for i in range(len(y)-2)]
            if debug:
                print("D", y)
        # Sort and select the middle element from sublists of length 3 in y

        return y
    # Return the result of the sub function

    y = sub(x)
    # Calculate the result y of the sub function for the given input x

    if y[0] == 2:
        pass
        sub(x, 1)
        print("=", x)
    # If the first element of y is 2, call the sub function recursively with x-1 and print x

    return y[0]
# Return the first element of the y list

if X == 1 or X == N * 2 - 1:
# Check if X is equal to 1 or N*2-1

    print("No")
# If it is, print "No"

else:
# Else, X is neither 1 nor N*2-1

    print("Yes")
# Print "Yes"

    if X == N * 2 - 2:
        xs = list(range(N-1, X+2)) + list(range(1, N-1))
    else:
        ys = list(range(1, X-1)) + list(range(X+3, N*2))
        xs = ys[:N-3] + [X+2, X-1, X, X+1] + ys[N-3:]
    # Calculate the list xs based on the value of X

    for x in xs:
        print(x)
# Print each element of the list xs