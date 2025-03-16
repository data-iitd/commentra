

import sys

# Initialize a variable firstTime to True
firstTime = True

# Initialize a variable step to 1
step = 1

# Read the first integer N from the standard input
N = int(input())

# Read the second integer K from the standard input
K = int(input())

# Read the string S from the standard input
S = input()

# Perform the main logic while K is greater than zero
while K > 0:
    # Create a new string T to store the reversed version of S
    T = S[::-1]

    # Create a new string revU to store the concatenation of S and T reversed
    revU = T + S[::-1]

    # Create a variable sDash to store the current substring of revU
    sDash = S

    # Iterate through the substrings of revU starting from the end of S
    for i in range(N, -1, -step):
        # Get the substring of revU starting from the current index i and of length N
        tmp = revU[i:i+N]

        # Compare the current substring tmp with the current substring sDash
        if sDash > tmp:
            # Update the current substring sDash with the new substring tmp
            sDash = tmp

    # Perform some actions based on the comparison of sDash and S
    if firstTime:
        firstTime = False
        # Check if the length of S raised to the power of K is greater than N
        if pow(2, K) > N:
            # Print the first character of S N times and exit the program
            print(sDash[0] * N)
            sys.exit(0)
    else:
        # Update the value of step
        step *= 2

    # Decrement the value of K
    K -= 1

    # Update the value of S to be the current substring sDash reversed
    S = sDash[::-1]

# Print the reversed version of the final string S
print(S[::-1])

