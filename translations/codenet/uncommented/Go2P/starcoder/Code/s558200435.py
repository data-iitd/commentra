n = int(input())
a = [int(input()) for i in range(n)]

b = []
for v in a:
	x = bisect.bisect_left(b, v)
	if x == len(b):
		b.append(v)
	else:
		b[x] = v

print(len(b))

