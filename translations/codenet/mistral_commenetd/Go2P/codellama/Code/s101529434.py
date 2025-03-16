
# Declare two integer variables, K and X
K, X = 0, 0

# Read two integers from the standard input and assign them to the variables K and X respectively
K, X = map(int, input().split())

# Check if the condition 500*K >= X is true
if 500*K >= X:
    # If the condition is true, print the string "Yes" to the standard output
    print("Yes")
else:
    # If the condition is false, print the string "No" to the standard output
    print("No")

