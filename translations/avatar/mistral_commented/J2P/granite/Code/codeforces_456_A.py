

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
temp = 0
q = 0
w = float('-inf')
e = float('-inf')
f = False

for i in range(n):
    if temp < a[i]:
        if q > b[i]:
            f = True
        q = b[i]
        temp = a[i]
    elif temp > a[i]:
        if q < b[i]:
            f = True
        q = b[i]
        temp = a[i]
    if a[i] > w:
        w = a[i]
        if b[i] < e:
            f = True
    elif a[i] < w:
        if b[i] > e:
            f = True

if f:
    print("Happy Alex")
else:
    print("Poor Alex")

