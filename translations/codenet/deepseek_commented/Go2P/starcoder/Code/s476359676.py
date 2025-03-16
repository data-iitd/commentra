
import sys

# Reads the next string from the input
def nextStr():
	return sys.stdin.readline().strip()

# Reads the next integer from the input
def nextInt():
	return int(nextStr())

n = nextInt()

ans = 0
aPrev = 0
for i in range(n):
	a = nextInt()
	if a > i or a > aPrev+1:
		print(-1)
		exit()
	if a == aPrev+1:
		ans += 1
	else:
		ans += a
	aPrev = a

print(ans)

# 