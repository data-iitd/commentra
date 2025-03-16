
# Read three strings from the user, separated by spaces
A, B, C = input().split()

# Calculate the lengths of strings A and B
la = len(A)
lb = len(B)

# Check if the last character of A matches the first character of B
# and if the last character of B matches the first character of C
if A[la - 1] == B[0] and B[lb - 1] == C[0]:
    # If both conditions are true, print "YES"
    print("YES")
else:
    # Otherwise, print "NO"
    print("NO")

