
def solve(a, b, c):
	temp_ = 0
	if c == a+b:
		temp_ = b + c
	elif c-1 > a+b:
		temp = (c - 1) - (a + b)
		temp_ = b + c - temp
	else:
		temp_ = b+c
	return temp_

a, b, c = map(int, input().split())
print(solve(a, b, c))

