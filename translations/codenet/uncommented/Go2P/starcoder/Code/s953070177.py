import sys

def get_next_string(fp):
	return fp.readline().strip()

def get_next_int(fp):
	return int(get_next_string(fp))

def get_next_int64(fp):
	return int(get_next_string(fp))

def main():
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1])

	scanner = get_next_string
	writer = sys.stdout

	n = get_next_int(scanner)

	aa = [0] * (n+2)
	sum = 0
	for i in range(n):
		aa[i+1] = get_next_int(scanner)
		sum += abs(aa[i+1] - aa[i])
	sum += abs(aa[n+1] - aa[n])

	for i in range(1, n+1):
		ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
		print(ans)

if __name__ == '__main__':
	main()

