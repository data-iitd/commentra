import sys

def main():
	INF = 10**11
	A = int(sys.stdin.readline())
	B = int(sys.stdin.readline())
	Q = int(sys.stdin.readline())
	s = [0] * (A+2)
	s[0], s[A+1] = -INF, INF
	for i in range(1, A+1):
		s[i] = int(sys.stdin.readline())

	t = [0] * (B+2)
	t[0], t[B+1] = -INF, INF
	for i in range(1, B+1):
		t[i] = int(sys.stdin.readline())

	for i in range(Q):
		x = int(sys.stdin.readline())
		b, d = bisect.bisect_left(s, x), bisect.bisect_left(t, x)
		res = INF
		for S in [s[b-1], s[b]]:
			for T in [t[d-1], t[d]]:
				d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T)
				res = min(res, min(d1, d2))

		print(res)

if __name__ == '__main__':
	main()

# 