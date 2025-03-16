import sys

def get_next_string(scanner):
	return scanner.readline().strip()

def get_next_int(scanner):
	return int(get_next_string(scanner))

def get_next_int64(scanner):
	return int64(get_next_string(scanner))

def get_next_uint64(scanner):
	return uint64(get_next_string(scanner))

def get_next_float64(scanner):
	return float64(get_next_string(scanner))

def main():
	scanner = sys.stdin
	writer = sys.stdout

	n = get_next_int(scanner)

	ans = "second"
	for i in range(n):
		a = get_next_int(scanner)
		if a%2 == 1:
			ans = "first"
			break
	print(ans)

if __name__ == "__main__":
	main()

