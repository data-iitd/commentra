import sys

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60

memo = [0] * ALPHABET_NUM
str = ""

def main():
	for line in sys.stdin:
		line = line.rstrip()
		if line == "