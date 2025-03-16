# Package main is the entry point of the program
import (
	# bufio package is used for reading and writing lines
	"bufio"
	# fmt package is used for formatted I/O
	"fmt"
	# os package is used for interacting with the operating system
	"os"
	# sort package is used for sorting arrays
	"sort"
	# string package is used for string operations
	"string"
	# sys package is used for system-specific parameters and functions
	"sys"
	# time package is used for measuring time
	"time"
)

# mainFn is the main function of the program
def mainFn():
	# Get the number of elements in the input array
	n = getInt()
	# Get the input array
	ls = getIntSlice(n)
	# Create a reversed copy of the input array
	lsRev = ls[:]
	# Copy the input array to the reversed copy
	lsRev.reverse()
	# Sort the input array in ascending order
	ls.sort()
	# Sort the reversed copy of the array in descending order
	lsRev.sort(reverse=True)

	# Initialize the answer variable
	ans = 0
	# Iterate through all pairs of elements in the array
	for i in range(n):
		for j in range(i+1, n):
			# Find the minimum and maximum elements of the current pair
			p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
			# Calculate the difference between the maximum and minimum elements
			x, y = q-p, q+p
			# Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
			l = ls.index(x, i)
			r = lsRev.index(y, 0, n-i)
			# Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
			sum = r - l
			# Check if the current pair lies within the range [l, r]
			if i >= l and i <= r:
				sum -= 1
			if j >= l and j <= r:
				sum -= 1
			# Ensure that the sum is not negative
			sum = max(0, sum)
			# Add the sum to the answer variable
			ans += sum
	# Divide the answer by 3 and print it
	ans /= 3
	puts(ans)
}

# min returns the minimum of two integers
def min(a, b):
	if a < b:
		return a
	return b

# max returns the maximum of two integers
def max(a, b):
	if a > b:
		return a
	return b

# -----------------------------------------

# Initialize some variables for reading and writing input/output
scanner = bufio.NewScanner(sys.stdin)
writer = bufio.NewWriter(sys.stdout)

# main is the entry point of the program
def main():
	# Set the buffer size for reading input
	#buf = 200001
	#scanner.Buffer(make([]byte, buf), buf)
	# Set the splitting function for reading input
	scanner.Split(bufio.ScanWords)
	# Call the main function
	mainFn()
	# Flush the writer buffer
	writer.Flush()
}

# getInt reads an integer from the standard input
def getInt():
	scanner.Scan()
	# Convert the input string to an integer and return it
	i = int(scanner.Text())
	return i
}

# getIntSlice reads an array of integers from the standard input
def getIntSlice(n):
	# Allocate memory for the array
	is = [0] * n
	# Read each element of the array from the standard input
	for i in range(n):
		is[i] = getInt()
	# Return the array
	return is
}

# getString reads a string from the standard input
def getsString():
	scanner.Scan()
	# Return the input string
	s = scanner.Text()
	return s
}

# puts writes the given arguments to the standard output, followed by a newline character
def puts(a):
	# Write the arguments to the writer buffer
	if _, err := fmt.Fprintln(writer, a); err!= None:
		raise(err)
}

