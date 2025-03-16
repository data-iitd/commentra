import sys

def nextInt(sc):
	sc.readline()
	return int(sc.readline())

class point:
	def __init__(self, x, l, r):
		self.x = x
		self.l = l
		self.r = r

def main():
	sc = sys.stdin
	N = nextInt(sc)
	points = []
	for i in range(N):
		x = nextInt(sc)
		l = nextInt(sc)
		points.append(point(x, x - l, x + l))
	points.sort(key=lambda p: p.r)
	start = points[0].r
	ans = 1
	for i in range(len(points)):
		if points[i].l < start:
			continue
		start = points[i].r
		ans += 1
	print(ans)

main()
# 