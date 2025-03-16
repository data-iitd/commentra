import sys

# <START-OF-CODE>

INF = 10**11

def main():
	A = int(sys.stdin.readline())
	B = int(sys.stdin.readline())
	Q = int(sys.stdin.readline())
	s = [0] + [int(sys.stdin.readline()) for _ in range(A)] + [INF]
	t = [0] + [int(sys.stdin.readline()) for _ in range(B)] + [INF]

	for i in range(Q):
		x = int(sys.stdin.readline())
		b, d = bisect.bisect_left(s, x), bisect.bisect_left(t, x)
		res = INF
		for S in [s[b-1], s[b]]:
			for T in [t[d-1], t[d]]:
				d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T)
				res = min(res, min(d1, d2))
		print(res)

main()

# 