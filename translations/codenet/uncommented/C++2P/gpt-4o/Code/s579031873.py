N, X = map(int, input().split())

ans = 0
min_value = 1000000000
for _ in range(N):
    tmp = int(input())
    X -= tmp
    ans += 1
    if tmp < min_value:
        min_value = tmp

ans += X // min_value

print(ans)

# <END-OF-CODE>
