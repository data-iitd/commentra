import sys
import math

# Run function processes input from the reader and writes output to the writer
def Run(r, w):
	# Initialize a new scanner to read input
	sc = NewScanner(r)

	# Read the first line of input and parse N (number of lines) and D (distance threshold)
	a = sc.ReadLine().Ints()
	N, D = a[0], a[1]

	# Read the next N lines of input, each containing a pair of integers
	lines = sc.ReadLines(N).Ints()

	# Initialize a counter for the number of points within the distance D
	count = 0
	# Iterate over each line of input
	for _, line in lines:
		# Calculate the Euclidean distance from the origin (0, 0)
		d = math.sqrt(line[0]*line[0] + line[1]*line[1])
		# Check if the distance is less than or equal to D
		if float(D) >= d:
			count += 1 # Increment the count if within distance
	# Output the total count of points within distance D
	fmt.Fprintln(w, count)

# main function serves as the entry point of the program
def main():
	# Call the Run function with standard input and output
	Run(sys.stdin, sys.stdout)

# Scanner struct wraps bufio.Scanner for reading input
class Scanner:
	def __init__(self, r):
		self.sc = bufio.NewScanner(r)

	# ReadLine reads a single line from the input and returns it as a Value
	def ReadLine(self):
		if self.sc.Scan():
			return Value(self.sc.Text())
		panic("scan error") # Panic if scanning fails

	# ReadLines reads n lines from the input and returns them as Values
	def ReadLines(self, n):
		var a Values
		# Loop to read n lines
		for i in range(0, n):
			a = append(a, self.ReadLine()) # Append each line to the Values slice
		return a # Return the slice of Values

# Value type represents a string value with additional methods for conversion
class Value(str):
	# String returns the string representation of the Value
	def String(self):
		return str(self)

	# Int converts the Value to an integer
	def Int(self):
		n, err = int(self), None
		if err!= None:
			panic(err) # Panic if conversion fails
		return n

	# Float64 converts the Value to a float64
	def Float64(self):
		f, err = float(self), None
		if err!= None:
			panic(err) # Panic if conversion fails
		return f

	# Strings splits the Value into a slice of strings
	def Strings(self):
		return str(self).split(" ")

	# Ints converts the Value to a slice of integers
	def Ints(self):
		var a []int
		# Split the Value into strings and convert each to an integer
		for _, s in self.Strings():
			n, err = int(s), None
			if err!= None:
				panic(err) # Panic if conversion fails
			a = append(a, n) # Append the integer to the slice
		return a # Return the slice of integers

	# Float64s converts the Value to a slice of float64
	def Float64s(self):
		var a []float64
		# Split the Value into strings and convert each to a float64
		for _, s in self.Strings():
			f, err = float(s), None
			if err!= None:
				panic(err) # Panic if conversion fails
			a = append(a, f) # Append the float64 to the slice
		return a # Return the slice of float64

	# Runes converts the Value to a slice of runes
	def Runes(self):
		return []rune(self)

# Values type represents a slice of Value
class Values(list):
	# Strings converts the Values to a slice of string slices
	def Strings(self):
		var a [][]string
		# Loop through each Value and convert to strings
		for _, value in self:
			a = append(a, value.Strings())
		return a # Return the slice of string slices

	# Ints converts the Values to a slice of integer slices
	def Ints(self):
		var a [][]int
		# Loop through each Value and convert to integers
		for _, value in self:
			a = append(a, value.Ints())
		return a # Return the slice of integer slices

	# Float64s converts the Values to a slice of float64 slices
	def Float64s(self):
		var a [][]float64
		# Loop through each Value and convert to float64
		for _, value in self:
			a = append(a, value.Float64s())
		return a # Return the slice of float64 slices

	# Runes converts the Values to a slice of rune slices
	def Runes(self):
		var a [][]rune
		# Loop through each Value and convert to runes
		for _, value in self:
			a = append(a, value.Runes())
		return a # Return the slice of rune slices

