N = int(input())

A = list(map(int, input().split()))  # Read N+1 integers for A
B = list(map(int, input().split()))  # Read N integers for B

ans = 0

for i in range(N):
    # site i
    if A[i] >= B[i]:
        ans += B[i]
        A[i] -= B[i]
        B[i] = 0
    else:
        ans += A[i]
        B[i] -= A[i]
        A[i] = 0

    # site i + 1
    if A[i + 1] >= B[i]:
        ans += B[i]
        A[i + 1] -= B[i]
        B[i] = 0
    else:
        ans += A[i + 1]
        B[i] -= A[i + 1]
        A[i + 1] = 0

print(ans)

# <END-OF-CODE>
