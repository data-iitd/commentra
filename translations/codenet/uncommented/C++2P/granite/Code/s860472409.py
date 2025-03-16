
N = int(input())
A = list(map(int, input().split()))
i = 0
ans = 0
count = 0
while i < N-1:
    if A[i] == A[i+1]:
        count += 1
        if count % 2!= 0:
            ans += 1
    else:
        count = 0
    i += 1
print(ans)
