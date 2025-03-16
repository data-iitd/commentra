import sys

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60

memo = [0] * ALPHABET_NUM
str = ""

def main():
	for line in sys.stdin:
		str = line.rstrip()
		if len(str) == 0:
			break
		for c in str:
			if 'a' <= c and c <= 'z':
				memo[ord(c) - ord('a')] += 1
			elif 'A' <= c and c <= 'Z':
				memo[ord(c) - ord('A')] += 1
			else:
				continue
	for i in range(ALPHABET_NUM):
		print(chr(i + ord('a')), ":", memo[i])

if __name__ == "__main__":
	main()

# 