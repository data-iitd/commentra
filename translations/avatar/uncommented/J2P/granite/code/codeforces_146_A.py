
n = int(input())
s = input()
l = list(s)
t = 0
for i in range(n):
    if l[i]!= '4' and l[i]!= '7':
        t = 1
        break
if t == 1:
    print("NO")
else:
    x = 0
    y = 0
    for i in range(n // 2):
        x += int(l[i])
    for i in range(n // 2, n):
        y += int(l[i])
    if x == y:
        print("YES")
    else:
        print("NO")
