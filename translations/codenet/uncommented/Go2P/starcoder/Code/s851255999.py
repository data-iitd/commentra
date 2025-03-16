n = int(input())
ws = []
for i in range(n):
    a, n = map(int, input().split())
    ws.append((a, n))
ws.sort(key=lambda x: x[1])

sum = 0
for a, n in ws:
    sum += a
    if sum > n:
        print("No")
        break
else:
    print("Yes")

