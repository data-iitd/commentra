
R = int(input())
G = int(input())
B = int(input())
N = int(input())

ans = 0
for x in range(N+1):
    for y in range(N+1):
        tmp = N - R*x - G*y
        if tmp >= 0 and tmp % B == 0:
            ans += 1

print(ans)

