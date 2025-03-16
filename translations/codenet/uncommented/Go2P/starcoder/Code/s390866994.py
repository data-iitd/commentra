import sys

def out(*args, **kwargs):
	print(*args, **kwargs)

def getInt():
	return int(sys.stdin.readline())

def getString():
	return sys.stdin.readline().strip()

def max(a, b):
	if a > b:
		return a
	return b

def min(a, b):
	if a < b:
		return a
	return b

def asub(a, b):
	if a > b:
		return a - b
	return b - a

def abs(a):
	if a >= 0:
		return a
	return -a

def main():
	N, C, K = map(int, input().split())
	t = list(map(int, input().split()))
	t.sort()
	# out(t)
	ans = 1
	cnt = 1
	end = t[0] + K
	for i in range(1, N):
		if cnt < C and t[i] <= end:
			cnt += 1
			# out(t[i])
		else:
			# out("----")
			# out(t[i])
			cnt = 1
			end = t[i] + K
			ans += 1
	out(ans)

main()
# 