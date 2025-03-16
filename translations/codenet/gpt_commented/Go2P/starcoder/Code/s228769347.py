import sys

# get_scanner initializes a new scanner for reading from the provided file pointer.
def get_scanner(fp):
	return bufio.Scanner(fp)

# get_next_string reads the next word from the scanner and returns it as a string.
def get_next_string(scanner):
	scanner.scan() # Read the next token.
	return scanner.text() # Return the text of the token.

# get_next_int converts the next word from the scanner to an integer and returns it.
def get_next_int(scanner):
	return int(get_next_string(scanner)) # Convert the string to an int.

# get_next_int64 converts the next word from the scanner to an int64 and returns it.
def get_next_int64(scanner):
	return int(get_next_string(scanner)) # Convert the string to an int64.

# get_next_uint64 converts the next word from the scanner to a uint64 and returns it.
def get_next_uint64(scanner):
	return int(get_next_string(scanner)) # Convert the string to a uint64.

# get_next_float64 converts the next word from the scanner to a float64 and returns it.
def get_next_float64(scanner):
	return float(get_next_string(scanner)) # Convert the string to a float64.

def main():
	fp = sys.stdin # Default input is standard input.
	wfp = sys.stdout # Default output is standard output.

	# Check for command-line arguments to read from a file and write to a file.
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r") # Open the input file if provided.
		if len(sys.argv) > 2:
			wfp = open(sys.argv[2], "w") # Create the output file if provided.

	scanner = get_scanner(fp) # Initialize the scanner for input.
	writer = bufio.NewWriter(wfp) # Create a buffered writer for output.

	n = get_next_int(scanner) # Read the number of integers.
	ll = [] # Create a slice to hold the integers.

	# Read n integers from the input.
	for i in range(n):
		ll.append(get_next_int(scanner)) # Populate the slice with integers.

	ll.sort() # Sort the slice of integers.

	ans = 0 # Initialize the answer counter.
	# Iterate through pairs of integers to find valid triplets.
	for i in range(n-2):
		for j in range(i+1, n-1):
			l = j + 1 # Start searching for the third element after the second element.
			r = n # Set the right boundary for binary search.
			# Perform binary search to find the count of valid third elements.
			for l < r:
				m = (l + r) >> 1 # Calculate the middle index.
				if ll[m] < ll[i]+ll[j]: # Check if the sum of the first two is greater than the middle element.
					l = m + 1 # Move the left boundary up.
					continue
				r = m # Move the right boundary down.
			# Count the number of valid third elements.
			ans += l - (j + 1) # Update the answer with the count of valid triplets.
	print(ans) # Print the result to the output.

	writer.flush() # Flush the buffered writer to ensure all output is written.

# 