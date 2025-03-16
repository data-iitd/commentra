# <START-OF-CODE>

n = int(input())
h = [int(x) for x in input().split()]

max = -1
flag = 0

for i in range(n):
    if max < h[i]:
        max = h[i]
    if max - h[i] >= 2:
        flag = 1

if flag == 1:
    print("No")
else:
    print("Yes")

# 