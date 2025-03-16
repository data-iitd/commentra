n = int(input())
h = list(map(int, input().split()))

max_height = -1
flag = False

for i in range(n):
    if max_height < h[i]:
        max_height = h[i]

    if max_height - h[i] >= 2:
        flag = True
        break

if flag:
    print("No")
else:
    print("Yes")
