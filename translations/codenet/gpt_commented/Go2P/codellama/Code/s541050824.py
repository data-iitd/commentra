
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// bufReader struct to handle buffered reading from standard input
type bufReader struct {
	r   *bufio.Reader // Buffered reader
	buf []byte        // Buffer to hold the read data
	i   int           // Current index in the buffer
}

// Initialize a global bufReader instance for reading input
var reader = &bufReader{
	bufio.NewReader(os.Stdin), // Create a new buffered reader from standard input
	make([]byte, 0),           // Initialize an empty buffer
	0,                          // Start index at 0
}

// readLine reads a line from the buffered reader into the buffer
func (r *bufReader) readLine() {
	// If the current index is less than the buffer length, return (buffer already filled)
	if r.i < len(r.buf):
		return
	r.buf = make([]byte, 0) # Reset the buffer
	r.i = 0 # Reset the index
	for:
		# Read a line from the reader
		line, isPrefix, err = r.r.ReadLine()
		if err != nil:
			panic(err) # Panic if there is an error
		r.buf = append(r.buf, line...) # Append the line to the buffer
		if not isPrefix: # If the line is not a prefix, break the loop
			break
	}
}

# Go:

# next retrieves the next token from the buffer
def next(self):
	self.readLine() # Ensure the buffer is filled
	from = self.i # Store the starting index of the token
	# Iterate through the buffer until a space is found
	for; self.i < len(self.buf):
		if self.buf[self.i] == ' ':
			break # Break on space
		self.i += 1
	s = str(self.buf[from:self.i]) # Extract the token from the buffer
	self.i += 1 # Move the index forward
	return s # Return the token

# Go:

# nextInt retrieves the next token and converts it to an int64
def nextInt(self):
	i, err = strconv.ParseInt(self.next(), 10, 64) # Parse the next token as int64
	if err != nil:
		panic(err) # Panic if there is an error in parsing
	return i # Return the parsed integer

# Go:

# nextLine is a wrapper to get the next line as a string
def nextLine(self):
	self.readLine() # Ensure the buffer is filled
	s = str(self.buf[self.i:]) # Get the remaining part of the buffer as a string
	self.i = len(self.buf) # Set index to the end of the buffer
	return s # Return the line

# Go:

# out prints the output to the buffered writer
def out(a):
	print(a, file=writer) # Print the arguments to the writer

# Go:

# max returns the maximum of two int64 values
def max(x, y):
	if x > y:
		return x # Return x if it is greater
	return y # Otherwise return y

# Go:

# min returns the minimum of two int64 values
def min(x, y):
	if x < y:
		return x # Return x if it is lesser
	return y # Otherwise return y

# Go:

# joinInts converts a slice of int64 to a string with a separator
def joinInts(a, sep):
	b = [str(v) for v in a] # Create a string slice to hold the converted integers
	return sep.join(b) # Join the strings with the specified separator

# Go:

# divUp performs ceiling division of x by y
def divUp(x, y):
	return (x + y - 1) // y # Return the result of ceiling division

# Go:

# solve contains the main logic for processing input and producing output
def solve():
	N = nextInt() # Read the number of pairs
	T, A = [0] * N, [0] * N # Initialize slices for T and A
	# Read pairs of integers into T and A
	for i in range(N):
		T[i], A[i] = nextInt(), nextInt() # Read each pair
	t, a = T[0], A[0] # Initialize t and a with the first pair
	# Iterate through the remaining pairs to compute the required values
	for i in range(1, N):
		r = max(divUp(t, T[i]), divUp(a, A[i])) # Calculate the required multiplier
		t, a = T[i] * r, A[i] * r # Update t and a based on the multiplier
	out(t + a) # Output the final result

# Go:

# main function where the program execution starts
def main():
	solve() # Call the solve function to execute the main logic
	writer.Flush() # Flush the buffered writer to output

# Go:

# END-OF-CODE