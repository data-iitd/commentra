

n = int(input())
ws = []
for i in range(n):
    a, n = map(int, input().split())
    ws.append((a, n))
ws.sort(key=lambda x: x[1])
sum = 0
for w in ws:
    sum += w[0]
    if sum > w[1]:
        print("No")
        exit()
print("Yes")
