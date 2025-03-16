
# Read three strings from user input
A = input()
B = input()
C = input()

# Calculate the lengths of the first two strings
la = len(A)
lb = len(B)

# Check if the last character of A is the same as the first character of B
# and if the last character of B is the same as the first character of C
if A[la - 1] == B[0] and B[lb - 1] == C[0]:
    # If both conditions are true, print "YES"
    print("YES")
else:
    # If either condition is false, print "NO"
    print("NO")

# End of code

