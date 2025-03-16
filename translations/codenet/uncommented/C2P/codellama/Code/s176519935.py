#include<stdio.h>

heap = []
sz = 0

def push(x):
	i = sz
	while i > 0:
		p = (i - 1) / 2
		if heap[p] >= x:
			break
		heap[i] = heap[p]
		i = p
	heap[i] = x
	sz += 1

def pop():
	ret = heap[0]
	x = heap[sz - 1]
	i = 0
	while i * 2 + 1 < sz:
		a = i * 2 + 1
		b = i * 2 + 2
		if b < sz and heap[b] > heap[a]:
			a = b
		if heap[a] <= x:
			break
		heap[i] = heap[a]
		i = a
	heap[i] = x
	sz -= 1
	return ret

def main():
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	for i in range(n):
		push(a[i])
	for i in range(m):
		tm = pop()
		tm //= 2
		push(tm)
	ans = 0
	for i in range(n):
		ans += heap[i]
	print(ans)

if __name__ == "__main__":
	main()

