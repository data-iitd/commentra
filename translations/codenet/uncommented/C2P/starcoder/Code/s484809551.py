
import sys

N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = (N_MAX * P_MAX / 32 + 1)

def compare_f(a, b):
	return a < b and -1 or 1

def comb(n, r):
	result = 1

	for i in range(0, r):
		result *= n - i
		result /= i + 1

	return result

def gcd(m, n):
	while m%n!= 0:
		temp = n
		n = m % n
		m = temp

	return n

def main():
	patternBase = "keyence"
	top = [0] * 8
	bottom = [0] * 8
	S = [0] * 101

	sys.stdin.readline()
	S = sys.stdin.readline()

	len = len(S)
	found = False

	for offset in range(0, len(patternBase)):
		top[0:offset] = patternBase[0:offset]
		top[offset] = '\0'
		bottom[0:len(patternBase) - offset] = patternBase[offset:len(patternBase)]
		bottom[len(patternBase) - offset] = '\0'

		topSearch = S.find(top)
		if topSearch!= -1:
			bottomSearch = S.rfind(bottom)
			if bottomSearch!= -1:
				sepCount = 0

				if topSearch!= 0:
					sepCount += 1
				if bottomSearch!= len(S) - len(bottom):
					sepCount += 1
				if len(S) - bottomSearch - len(bottom)!= 0:
					sepCount += 1

				if sepCount <= 1:
					found = True
					break

	print "YES" if found else "NO"

if __name__ == "__main__":
	main()

