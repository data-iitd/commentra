
n, m = map(int, input().split())
foods = [0] * m
for _ in range(n):
    k, *temp = map(int, input().split())
    for food in temp:
        foods[food - 1] += 1
ans = sum(1 for food in foods if food == n)
print(ans)

