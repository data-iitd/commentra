# Package main is the entry point of the program
import (
	# Importing necessary packages
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

def solve():
	# Function to solve the problem
	n = getInt() # Read the number of elements in the array
	as = getIntSlice(n) # Read the array elements

	# Initialize an array xs of size n
	xs = [0] * n
	# Iterate through the array as and assign the value xs[i]
	for i, a in enumerate(as):
		xs[i] = a - i + 1 # Assign the value xs[i] = a - i + 1
	# Sort the array xs in ascending order
	sort.Ints(xs)

	# Assign the middle element of the sorted array xs to variable b
	b = xs[n//2]
	# Initialize variable ans with 0
	ans = 0
	# Iterate through the array xs and calculate the absolute difference between each element and b
	for _, x in enumerate(xs):
		ans += abs(x - b) # Calculate the absolute difference and add it to ans
	# Print the answer
	fmt.Fprintln(wr, ans)

def abs(n):
	# Function to calculate the absolute difference of a number
	if n < 0:
		# If the number is negative, return the negative number with the minus sign removed
		return -n
	# If the number is non-negative, return the number itself
	return n

# -----------------------------------------

const (
	inf = 1 << 60 # Constant inf is set to 2^60
	# mod = 1000000007 # Constant mod is set to 1000000007
)

var (
	sc = bufio.NewScanner(os.Stdin) # Variable sc is initialized as a new bufio.Scanner with standard input as the source
	wr = bufio.NewWriter(os.Stdout) # Variable wr is initialized as a new bufio.Writer with standard output as the destination
)

def main():
	# Main function
	maxBufSize = 100000000 # Set the maximum buffer size to 100,000,000
	sc.Buffer(bytearray(make([]byte, 4096)), maxBufSize) # Set the buffer size for scanner
	sc.Split(bufio.ScanWords)                 # Set the splitting function for scanner
	solve()                                   # Call the solve function
	wr.Flush()                               # Flush the writer buffer
}

def getInt():
	# Function to read an integer from standard input
	sc.Scan() # Read the next token
	ret, err = int(sc.Text()), error(None) # Convert the token to an integer
	if err!= None:
		panic(err) # If there is an error, panic
	return ret
}

def getIntSlice(n):
	# Function to read an array of n integers from standard input
	ret = [0] * n # Initialize the array with size n
	for i in range(n):
		ret[i] = getInt() # Read each integer and assign it to the corresponding index in the array
	return ret
}

def getString():
	# Function to read a string from standard input
	sc.Scan() # Read the next token
	ret = str(sc.Text()) # Assign the token as the string
	return ret
}

def getRunes():
	# Function to read a rune string from standard input
	ret = []rune(getString()) # Convert the string to a rune slice
	return ret
}

