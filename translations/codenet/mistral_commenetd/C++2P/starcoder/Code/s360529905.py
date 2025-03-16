#include <cstdio>
#include <algorithm>

def main():
	N = int(raw_input())
	a = [int(raw_input()) for i in range(N)]
	b = a[:]
	sort(b)
	frontHalf = b[N/2-1]
	backHalf = b[N/2]
	for i in range(N):
		if a[i] < backHalf:
			print backHalf
		else:
			print frontHalf

main()

