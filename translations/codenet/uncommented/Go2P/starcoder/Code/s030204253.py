n = int(input())
a = [float(input()) for i in range(n)]
for i in range(n-1):
	a = sorted(a)
	a = a[2:]
	a.append((a[0]+a[1])/2)
print(a[0])

