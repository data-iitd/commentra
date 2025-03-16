# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

import sys

def getint():
	return int(sys.stdin.readline())

def main():
	buf = sys.stdin.readline()
	w = getint()
	sys.stdin.readline()
	a = [0] * (w+1)
	b = [0] * (w+1)
	ans = 0
	f = 0
	for i in range(1, w+1):
		a[i] = k = getint()
		if not k: f |= 1
		elif k < 0: f |= 2
		else: ans += k
	if not ans or not (f & 1):
		print('0')
		return
	if not (f & 2):
		print(ans)
		return
	close = 0
	f = 0
	for i in range(1, w+1):
		if not a[i]: close = INF; f = -1
		elif a[i] < 0:
			if f < 0 or close - (i-f) > -a[i]:
				close = -a[i]
				f = i
		else:
			if f < 0: b[i] = INF
			else:
				k = close - (i-f)
				if k < 0: k = 0
				b[i] = k
	close = 0
	f = w
	for i in range(w, 0, -1):
		if not a[i]: close = INF; f = -1
		elif a[i] < 0:
			if f < 0 or close - (f-i) > -a[i]:
				close = -a[i]
				f = i
		else:
			if f < 0: b[i] = INF
			else:
				k = close - (f-i)
				if k < 0: k = 0
				if k > b[i]: b[i] = k
	for i in range(1, w+1):
		if a[i] > 0:
			if b[i] > a[i]: ans += a[i]
			else: ans += b[i]
	print(ans)

if __name__ == '__main__':
	main()

