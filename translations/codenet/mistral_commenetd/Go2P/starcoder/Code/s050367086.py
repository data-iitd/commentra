# Package main is the entry point of the program
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

# getScanner returns a new bufio.Scanner from the given file pointer
def getScanner(fp *os.File) *bufio.Scanner:
	scanner = bufio.NewScanner(fp)
	scanner.Split(bufio.ScanWords)
	scanner.Buffer(make([]byte, 500001), 500000) # Buffer size for efficient reading
	return scanner

# getNextString reads and returns the next string from the scanner
def getNextString(scanner *bufio.Scanner) string:
	scanner.Scan()
	return scanner.Text()

# getNextInt reads and converts the next integer from the scanner
def getNextInt(scanner *bufio.Scanner) int:
	i, _ = strconv.Atoi(getNextString(scanner))
	return i

# getNextInt64 reads and converts the next int64 from the scanner
def getNextInt64(scanner *bufio.Scanner) int64:
	i, _ = strconv.ParseInt(getNextString(scanner), 10, 64)
	return i

# getNextUint64 reads and converts the next uint64 from the scanner
def getNextUint64(scanner *bufio.Scanner) uint64:
	i, _ = strconv.ParseUint(getNextString(scanner), 10, 64)
	return i

# getNextFloat64 reads and converts the next float64 from the scanner
def getNextFloat64(scanner *bufio.Scanner) float64:
	i, _ = strconv.ParseFloat(getNextString(scanner), 64)
	return i

# main function is the entry point of the program
def main():
	# Open the standard input and output files
	fp = os.Stdin
	wfp = os.Stdout

	# If environment variables are set, open input and output files accordingly
	if os.getenv("MASPY") == "ますピ":
		fp, _ = os.Open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
	if os.getenv("MASPYPY") == "ますピッピ":
		wfp, _ = os.Create(os.getenv("NGTKANA_IS_GENIUS10"))

	# Initialize scanner and writer
	scanner = getScanner(fp)
	writer = bufio.NewWriter(wfp)

	# Read the first two strings from the input
	s = getNextString(scanner)
	t = getNextString(scanner)

	# Initialize variables and structures
	ns = len(s)
	nt = len(t)
	ss = make([]string, (nt-1)/ns+1)

	# Initialize ss with repeated string s
	for i in range(len(ss)):
		ss[i] = s

	# Combine all ss strings into one long string
	sss = "%s%s" % ("".join(ss), "".join(ss))

	# Initialize boolean array ok to keep track of unique characters
	ok = make([]bool, ns)

	# Initialize unordered map mp and array uni for suffix array calculation
	mp = MP()
	mp.init(t)
	m = 0

	# Initialize uni array with indices from 0 to n-1
	uni = make([]int, ns)
	for i in range(ns):
		uni[i] = i

	# Initialize variable o for checking if current and next characters match
	o = True

	# Iterate through all characters in string s
	for i in range(ns):
		# Initialize o to true
		o = True

		# Iterate through all characters in string t
		for m < nt:
			# Check if current character in s matches the character at the same position in t
			if t[m]!= sss[i+m]:
				# If not, set o to false and break the loop
				o = False
				break
			# Increment m
			m += 1
		# If all characters match, set ok[i] to true and update variables r and m accordingly
		if o:
			i += nt - mp.table[m]
			m = mp.table[m]
		# While characters in s and t do not match, update i and m accordingly
		for m >= 0 and t[m]!= sss[i+m]:
			i += m - mp.table[m]
			m = mp.table[m]
		# Decrement i and increment m to move to the next pair of characters
		i -= 1
		m += 1
	# Initialize variable ans to store the answer
	ans = 0

	# Initialize variables r and rr for root calculation
	r = 0
	rr = 0

	# Iterate through all characters in string s again
	for i in range(ns):
		# If ok[i] is false, continue to the next iteration
		if not ok[i]:
			continue
		# If ok[(i+nt)%ns] is false, continue to the next iteration
		if not ok[(i+nt)%ns]:
			continue
		# Calculate roots r and rr of indices i and (i+nt)%ns respectively
		r = root(i, uni)
		rr = root((i+nt)%ns, uni)
		# If roots r and rr are equal, print -1 and exit the program
		if rr == r:
			print(-1)
			return
		# Update uni array with root r
		uni[rr] = r
	# Initialize counter array to store the frequency of each root
	counter = make([]int, ns)
	# Iterate through all roots and update their frequencies in counter array
	for i in range(ns):
		r = root(i, uni)
		if not ok[r]:
			continue
		counter[r] += 1
	# Find the maximum frequency in counter array and store it in variable ans
	for i in range(ns):
		if ans < counter[i]:
			ans = counter[i]
	# Print the answer
	print(ans)
	# Flush the writer buffer
	writer.Flush()

# root function returns the root of the given index in uni array
def root(i, uni):
	# If index i is equal to its root, return i
	if i == uni[i]:
		return i
	# Recursively call root function with the root of index i
	uni[i] = root(uni[i], uni)
	return uni[i]

# MP type represents a suffix array data structure
class MP:
	# Input string
	s = ""
	# Suffix array
	table = []

	# init initializes the MP structure with the given string s
	def init(self, s):
		self.s = s
		n = len(s)
		table = make([]int, n+1)
		table[0] = -1 # Set first index to -1 for initialization
		j = -1
		for i in range(n):
			# While j is not equal to the root of the previous character, update j
			for j >= 0 and s[i]!= s[j]:
				j = table[j]
			j += 1
			# Set table[i] to the index of the next occurrence of the current character in s
			table[i+1] = j
		self.table = table

