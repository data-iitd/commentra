
#<START-OF-CODE>
N = int(input())
A = [int(x) for x in input().split()]
ans = 0
count = 0
for i in range(N-1):
    if A[i] == A[i+1]:
        count += 1
        if count%2!= 0:
            ans += 1
    else:
        count = 0
print(ans)
#