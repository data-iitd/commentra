import sys

def get_scanner(fp):
	return bufio.Scanner(fp)

def get_next_string(scanner):
	scanner.scan()
	return scanner.text()

def get_next_int(scanner):
	return int(get_next_string(scanner))

def get_next_int64(scanner):
	return int(get_next_string(scanner))

def get_next_uint64(scanner):
	return int(get_next_string(scanner))

def get_next_float64(scanner):
	return float(get_next_string(scanner))

def main():
	fp = sys.stdin
	wfp = sys.stdout
	cnt = 0

	if os.getenv("MASPY") == "ますピ":
		fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
		cnt = 2
	if os.getenv("MASPYPY") == "ますピッピ":
		wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

	scanner = get_scanner(fp)
	writer = bufio.Writer(wfp)
	solve(scanner, writer)
	for i in range(cnt):
		print("-----------------------------------", file=writer)
		solve(scanner, writer)
	writer.flush()

def solve(scanner, writer):
	k = get_next_int(scanner)
	x = get_next_int(scanner)

	ans = "No"
	if k*500 >= x:
		ans = "Yes"
	print(ans, file=writer)

if __name__ == "__main__":
	main()

