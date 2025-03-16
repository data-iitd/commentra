
n = int(input())
h = list(map(int, input().split()))
max_h = max(h)
flag = False
for i in range(n):
    if max_h - h[i] >= 2:
        flag = True
        break
if flag:
    print("No")
else:
    print("Yes")

