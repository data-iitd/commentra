import sys

# get_scanner Function
# Purpose: Initializes a scanner for the given file pointer.
# Details: Creates a new scanner and sets it to scan words.
def get_scanner(fp):
	scanner = fp.readline
	return scanner

# get_next_string Function
# Purpose: Retrieves the next word from the scanner.
# Details: Scans the next word and returns it.
def get_next_string(scanner):
	return scanner().strip()

# get_next_int Function
# Purpose: Retrieves the next word and converts it to an integer.
# Details: Uses `get_next_string` and `int`.
def get_next_int(scanner):
	return int(get_next_string(scanner))

# get_next_int64 Function
# Purpose: Retrieves the next word and converts it to an int64.
# Details: Uses `get_next_string` and `int`.
def get_next_int64(scanner):
	return int(get_next_string(scanner))

# get_next_uint64 Function
# Purpose: Retrieves the next word and converts it to a uint64.
# Details: Uses `get_next_string` and `int`.
def get_next_uint64(scanner):
	return int(get_next_string(scanner))

# get_next_float64 Function
# Purpose: Retrieves the next word and converts it to a float64.
# Details: Uses `get_next_string` and `float`.
def get_next_float64(scanner):
	return float(get_next_string(scanner))

# main Function
# Purpose: Main entry point of the program.
# Details: Sets up input/output streams, reads strings, initializes pattern matching, and performs the main logic.
def main():
	fp = sys.stdin
	wfp = sys.stdout

	if os.getenv("MASPY") == "ますピ":
		fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r")
	if os.getenv("MASPYPY") == "ますピッピ":
		wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

	scanner = get_scanner(fp)
	writer = wfp.write

	s = get_next_string(scanner)
	t = get_next_string(scanner)

	ns = len(s)
	nt = len(t)
	ss = [s for i in range(nt//ns+1)]

	for i in range(len(ss)):
		ss[i] = s

	sss = "".join(ss) + "".join(ss)

	ok = [False for i in range(ns)]

	uni = [i for i in range(ns)]
	mp = MP()
	mp.init(t)
	m = 0
	for i in range(ns):
		uni[i] = i
	o = True
	for i in range(ns):
		o = True
		for m < nt:
			if t[m]!= sss[i+m]:
				o = False
				break
			m += 1
		ok[i] = o
		if o:
			i += nt - mp.table[m]
			m = mp.table[m]
		for m >= 0 and t[m]!= sss[i+m]:
			i += m - mp.table[m]
			m = mp.table[m]
		i -= 1
		m += 1

	ans = 0
	r, rr = 0, 0
	for i in range(ns):
		if ok[i] == False:
			continue
		if ok[(i+nt)%ns] == False:
			continue
		r = root(i, uni)
		rr = root((i+nt)%ns, uni)
		if rr == r:
			writer("-1\n")
			return
		uni[rr] = r

	counter = [0 for i in range(ns)]
	for i in range(ns):
		r = root(i, uni)
		if ok[r] == False:
			continue
		counter[r] += 1
	for i in range(ns):
		if ans < counter[i]:
			ans = counter[i]

	writer(str(ans) + "\n")

# root Function
# Purpose: Implements the union-find structure to find the root of a node.
# Details: Uses path compression to optimize the union-find structure.
def root(i, uni):
	if i == uni[i]:
		return i
	uni[i] = root(uni[i], uni)
	return uni[i]

# MP Struct and init Method
# Purpose: Manages the pattern and its pre-processing table for the Boyer-Moore algorithm.
# Details: Initializes the pattern and builds the pre-processing table.
class MP:
	def __init__(self):
		self.s = ""
		self.table = []

	def init(self, s):
		self.s = s
		n = len(s)
		table = [0 for i in range(n+1)]
		table[0] = -1
		j = -1
		for i in range(n):
			for j >= 0 and s[i]!= s[j]:
				j = table[j]
			j += 1
			table[i+1] = j
		self.table = table

# 