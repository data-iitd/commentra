N = int(input())
A = [int(x) for x in input().split()]
ans = 0
i = 0
count = 0
while i+1 < N:
    if A[i] == A[i+1]:
        count += 1
        if count % 2!= 0:
            ans += 1
    else:
        count = 0
    i += 1
print(ans)

