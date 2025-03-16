n, m = map(int, input().split())

foods = [0] * m

for _ in range(n):
    k = int(input())
    for _ in range(k):
        temp = int(input()) - 1
        foods[temp] += 1

ans = sum(1 for elem in foods if elem == n)

print(ans)

# <END-OF-CODE>
