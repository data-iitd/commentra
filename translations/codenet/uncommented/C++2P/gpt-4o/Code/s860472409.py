N = int(input())
A = list(map(int, input().split()))

i = 0
ans = 0
count = 0

while i + 1 < N:  # Ensure we don't go out of bounds
    if A[i] == A[i + 1]:
        count += 1
        if count % 2 != 0:
            ans += 1
    else:
        count = 0
    i += 1

print(ans)
# <END-OF-CODE>
