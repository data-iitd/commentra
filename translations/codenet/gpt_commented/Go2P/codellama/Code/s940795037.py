
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

# Main function where the execution starts
def main():
	# Create a new scanner to read input
	sc = Scanner()

	# Read the number of integers to process
	n = sc.nextInt()
	ans = 0.0

	# Loop through each integer, calculate the reciprocal, and accumulate the sum
	for i in range(n):
		tmp = 1 / float(sc.nextInt())
		ans += tmp

	# Print the harmonic mean of the input integers
	print(1/ans)

# Scanner struct to handle input reading efficiently
class Scanner:
	def __init__(self):
		self.r = bufio.Reader(sys.stdin) # Create a buffered reader for input
		self.buf = [] # Buffer to hold the input line
		self.p = 0 # Current position in the buffer

	# Next reads the next token from the input
	def next(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		# Iterate through the buffer to find the next space
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] == ' ':
				break # Stop at the first space
		result = ''.join(self.buf[start:self.p]) # Extract the token
		self.p++ # Move past the space
		return result # Return the token

	# NextLine reads the next full line from the input
	def nextLine(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		self.p = len(self.buf) # Move to the end of the buffer
		return ''.join(self.buf[start:]) # Return the line

	# NextInt reads the next integer from the input
	def nextInt(self):
		v = int(self.next()) # Convert the next token to an integer
		return v # Return the integer

	# NextIntArray reads a space-separated array of integers from the input
	def nextIntArray(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		result = [] # Initialize an empty slice for the results
		# Iterate through the buffer to find integers separated by spaces
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] == ' ':
				v = int(''.join(self.buf[start:self.p])) # Convert the token to an integer
				result.append(v) # Append the integer to the result slice
				start = self.p + 1 # Update the start position
		v = int(''.join(self.buf[start:self.p])) # Convert the last token to an integer
		result.append(v) # Append the last integer to the result slice

		return result # Return the slice of integers

	# NextMap reads a space-separated list of integers into a map
	def nextMap(self):
		self.pre() # Ensure there is data to read
		start = self.p # Mark the start position
		mp = {} # Initialize an empty map
		# Iterate through the buffer to find integers separated by spaces
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] == ' ':
				v = int(''.join(self.buf[start:self.p])) # Convert the token to an integer
				mp[v] = True # Add the integer to the map
				start = self.p + 1 # Update the start position
		v = int(''.join(self.buf[start:self.p])) # Convert the last token to an integer
		mp[v] = True # Add the last integer to the map

		return mp # Return the map of integers

	# pre checks if there is data to read and reads a new line if necessary
	def pre(self):
		if self.p >= len(self.buf): # If the current position is at the end of the buffer
			self.readLine() # Read a new line
			self.p = 0 # Reset the position to the start of the new line

	# readLine reads a full line from the input and stores it in the buffer
	def readLine(self):
		self.buf = [] # Reset the buffer
		while True:
			l, p, e = self.r.readline() # Read a line from the buffered reader
			if e != None:
				raise e # Panic if there is an error
			self.buf.extend(l) # Append the line to the buffer
			if not p: # If the line is not a continuation
				break # Exit the loop

# 