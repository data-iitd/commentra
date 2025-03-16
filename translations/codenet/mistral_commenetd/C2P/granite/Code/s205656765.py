
# Python code to solve the problem

# Import necessary libraries

# Input values for A, B, C, and X from the user
A = int(input())
B = int(input())
C = int(input())
X = int(input())

# Divide X by 50 and assign the quotient to X
X = X // 50

# Initialize the counter kosu to zero
kosu = 0

# Three nested for loops to check if X can be represented as 10*i + 2*j + k
for i in range(A+1): # Loop through all possible values of i from 0 to A
    for j in range(B+1): # Loop through all possible values of j from 0 to B
        for k in range(C+1): # Loop through all possible values of k from 0 to C
            if X == (10*i) + (2*j) + k: # Check if X equals the sum of 10*i, 2*j, and k
                kosu += 1 # If so, increment the counter kosu

# Print the result, which is the number of ways X can be represented as 10*i + 2*j + k
print(kosu)

# End of Python code

