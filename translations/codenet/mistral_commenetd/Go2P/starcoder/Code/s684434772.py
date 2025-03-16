# Package main contains the main function for solving the problem.
import (
	# bufio package is used for reading input from the standard input.
	"bufio"
	# fmt package is used for printing output to the standard output.
	"fmt"
	# os package is used for reading input from the standard input.
	"os"
	# re package is used for regular expressions.
	"re"
	# strconv package is used for converting strings to integers and integers to strings.
	"strconv"
)

# The main function is the entry point of the program.
def main():
	# Initialize a new Scanner object named'sc'.
	sc = NewScanner()

	# Read 'n' and 'k' from the standard input.
	n = sc.ReadInt()
	k = sc.ReadInt()

	# Initialize a variable 'total' to store the sum of combinations.
	total = 0

	# Calculate the sum of combinations of 'n' taken 'i' at a time, where 'i' ranges from 'k' to 'n+1'.
	for i in range(k, n+1):
		# Calculate the number of combinations using the combi function.
		comb = combi(n, i)
		# Add the number of combinations to the 'total' variable.
		total += comb
		# Apply modulo operation to reduce the size of the number.
		total = total % (1000000007)

	# Print the result to the standard output.
	fmt.Println(total)
}

# The combi function calculates the number of combinations of 'n' taken 'k' at a time using a simplified formula.
def combi(n, k):
	# Calculate the minimum and maximum number of combinations.
	min = (k-1) * k / 2
	max = (2*n-k+1) * k / 2
	# Return the difference between the maximum and minimum number of combinations.
	return int(max - min + 1)

# Util functions for performing basic mathematical operations.

# Abs returns the absolute value of a given integer.
def Abs(x):
	# If the number is positive, return the number itself.
	# Otherwise, return the negative of the number.
	if x >= 0:
		return x
	return -x

# Min returns the minimum value among the given integers.
def Min(values):
	# Initialize the minimum value with the first integer.
	min = values[0]
	# Compare each integer with the minimum value and update the minimum value if necessary.
	for _, v in values:
		if v < min:
			min = v
	# Return the minimum value.
	return min

# Max returns the maximum value among the given integers.
def Max(values):
	# Initialize the maximum value with the first integer.
	max = values[0]
	# Compare each integer with the maximum value and update the maximum value if necessary.
	for _, v in values:
		if v > max:
			max = v
	# Return the maximum value.
	return max

# Pow returns the result of raising the base to the given exponent.
def Pow(base, exponent):
	# Initialize the answer with 1.
	answer = 1
	# Multiply the answer with the base for each bit in the exponent.
	for i in range(0, exponent):
		answer *= base
	# Return the answer.
	return answer

# Abs64 returns the absolute value of a given integer64.
def Abs64(x):
	# If the number is positive, return the number itself.
	# Otherwise, return the negative of the number.
	if x >= 0:
		return x
	return -x

# Min64 returns the minimum value among the given integer64s.
def Min64(values):
	# Initialize the minimum value with the first integer.
	min = values[0]
	# Compare each integer with the minimum value and update the minimum value if necessary.
	for _, v in values:
		if v < min:
			min = v
	# Return the minimum value.
	return min

# Max64 returns the maximum value among the given integer64s.
def Max64(values):
	# Initialize the maximum value with the first integer.
	max = values[0]
	# Compare each integer with the maximum value and update the maximum value if necessary.
	for _, v in values:
		if v > max:
			max = v
	# Return the maximum value.
	return max

# Pow64 returns the result of raising the base to the given exponent.
def Pow64(base, exponent):
	# Initialize the answer with 1.
	answer = 1
	# Multiply the answer with the base for each bit in the exponent.
	for i in range(0, exponent):
		answer *= base
	# Return the answer.
	return answer

# Scanner struct is used to read input from the standard input.
class Scanner:
	# bufio.Scanner is used to read input from the standard input.
	bufScanner = None

	# NewScanner initializes a new Scanner object.
	def __init__(self):
		# Initialize a new bufio.Scanner object named 'bufSc'.
		self.bufScanner = bufio.NewScanner(os.Stdin)
		# Set the splitting function of bufio.Scanner to scan words.
		self.bufScanner.Split(bufio.ScanWords)

	# ReadString reads a string from the standard input.
	def ReadString(self):
		# Read a word from the standard input using bufio.Scanner.
		self.bufScanner.Scan()
		# Return the read word as a string.
		return self.bufScanner.Text()

	# ReadInt reads an integer from the standard input.
	def ReadInt(self):
		# Read a word from the standard input using bufio.Scanner.
		self.bufScanner.Scan()
		# Convert the read word to an integer using strconv.Atoi.
		num, err = strconv.Atoi(self.bufScanner.Text())
		# If an error occurs, panic with the error message.
		if err!= None:
			panic(err)
		# Return the read integer.
		return num

	# ReadInt64 reads an integer64 from the standard input.
	def ReadInt64(self):
		# Read a word from the standard input using bufio.Scanner.
		self.bufScanner.Scan()
		# Convert the read word to an integer64 using strconv.ParseInt.
		num, err = strconv.ParseInt(self.bufScanner.Text(), 10, 64)
		# If an error occurs, panic with the error message.
		if err!= None:
			panic(err)
		# Return the read integer64.
		return num

