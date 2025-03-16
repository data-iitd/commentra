n, m = map(int, input().split())

foods = [0] * m

for _ in range(n):
    k = int(input())
    preferences = list(map(lambda x: int(x) - 1, input().split()))
    
    for pref in preferences:
        foods[pref] += 1

ans = 0
for elem in foods:
    if elem == n:
        ans += 1

print(ans)
