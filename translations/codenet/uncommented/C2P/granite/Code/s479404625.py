
A, B, C = input().split()

la = len(A)
lb = len(B)

if A[-1] == B[0] and B[-1] == C[0]:
    print("YES")
else:
    print("NO")
