A, B, C = input().split()

la = len(A)
lb = len(B)

if A[la - 1] == B[0] and B[lb - 1] == C[0]:
    print("YES")
else:
    print("NO")

# <END-OF-CODE>
