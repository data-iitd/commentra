
import sys

heap = []
sz = 0

def push(x):
	global sz
	i = sz
	while i > 0:
		p = (i-1)/2
		if heap[p] >= x:
			break
		heap[i] = heap[p]
		i = p
	heap[i] = x
	sz += 1

def pop():
	global sz
	ret = heap[0]
	x = heap[sz-1]
	i = 0
	while i*2+1 < sz:
		a = i*2+1
		b = i*2+2
		if b < sz and heap[b] > heap[a]:
			a = b
		if heap[a] <= x:
			break
		heap[i] = heap[a]
		i = a
	heap[i] = x
	sz -= 1
	return ret

n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
for i in a:
	push(i)
for i in range(m):
	pop()
ans = 0
for i in range(n):
	ans += heap[i]
print ans

