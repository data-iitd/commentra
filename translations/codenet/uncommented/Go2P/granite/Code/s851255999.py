
# Your code here!
n = int(input())
ws = [list(map(int, input().split())) for _ in range(n)]
ws.sort(key=lambda x: x[1])

sum = 0
for w in ws:
    sum += w[0]
    if sum > w[1]:
        print("No")
        exit()
print("Yes")

