
import sys

def main():
	m = {}
	N, M = map(int, input().split())
	for i in range(N):
		m[int(input())] = m.get(int(input()), 0) + 1
	for i in range(M):
		B, C = map(int, input().split())
		m[C] = m.get(C, 0) + B
	ints = list(m.keys())
	ints.sort(reverse=True)
	rest = N
	sum = 0
	for i in ints:
		num = m[i]
		if num >= rest:
			sum += rest * i
			break
		sum += num * i
		rest -= num
	print(sum)

if __name__ == "__main__":
	main()

