# Declare three strings A, B, and C
A, B, C = input().split()

# Calculate the length of strings A and B
la = len(A)
lb = len(B)

# Check if the last character of string A is the same as the first character of string B
# and the last character of string B is the same as the first character of string C
if A[la - 1] == B[0] and B[lb - 1] == C[0]:
    # If the condition is true, print YES
    print("YES")
else:
    # If the condition is false, print NO
    print("NO")

# <END-OF-CODE>
