
#include<stdio.h>

def main():
	while True:
		n = int(input())
		if n == 0:
			break
		r = (n + 1) / 2 + 1
		c = (n + 1) / 2
		cnt = 1
		arr = [[0 for i in range(n+1)] for j in range(n+1)]
		arr[r][c] = cnt
		flag = 1
		while cnt!= n*n + 1:
			cnt += 1
			if flag:
				r += 1
				c += 1
				if c > n:
					c = 1
				if r > n:
					r = 1
				if arr[r][c]:
					flag = 0
					cnt -= 1
				else:
					arr[r][c] = cnt
			else:
				r += 1
				c -= 1
				if c < 1:
					c = n
				if r > n:
					r = 1
				if arr[r][c]:
					flag = 0
				else:
					arr[r][c] = cnt
					flag = 1
			#print("r=%d  c=%d   cnt=%d" % (r, c, cnt))
		for r in range(1, n+1):
			for c in range(1, n+1):
				print("%4d" % arr[r][c], end="")
				arr[r][c] = 0
				if c == n:
					print()

main()

