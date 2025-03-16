n = int(input())
a = [float(input()) for i in range(n)]
while len(a) > 1:
    a = sorted(a[2:])
    a = [a[0] + a[1]] + a[2:]
print(a[0])

