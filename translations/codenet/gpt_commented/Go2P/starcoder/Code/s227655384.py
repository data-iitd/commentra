import sys
import io
import bisect

# ReadLongLines reads a specified number of long lines from standard input.
def ReadLongLines(times):
	result = [] # Create a slice to hold the lines read
	reader = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8') # Create a buffered reader for standard input
	buffer = "" # Buffer to accumulate line data
	readBytes = 0 # Initialize readBytes to track the number of bytes read

	# Loop to read the specified number of lines
	for i in range(times):
		for {
			readBuf = reader.readline() # Read a line from input
			readBytes += len(readBuf) + 1 # Update the byte count
			if readBuf == "": # Check for end of file
				print("EOF")
				break
			buffer += readBuf # Append the read buffer to the accumulator
			if not readBuf.endswith("\n"): # Check if the line is complete (not a prefix)
				result.append(buffer) # Store the complete line in the result
				buffer = "" # Reset the buffer for the next line
				break # Break out of the inner loop to read the next line
		}
	}
	# Seek back to the previous position to avoid reading ahead
	sys.stdin.seek(-readBytes, io.SEEK_CUR)
	return result # Return the lines read

# Console class for handling output
class Console:
	def __init__(self):
		self.writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8', write_through=True) # Create a new writer for standard output

	# Printf formats and writes output to the console
	def Printf(self, format, a):
		self.writer.write(format % a) # Format and write to the buffered writer

	# Println writes a string followed by a newline to the console
	def Println(self, s):
		self.writer.write(s + "\n") # Write the string to the buffered writer

	# Close flushes the buffered writer
	def Close(self):
		self.Flush() # Ensure all buffered data is written out

	# Flush flushes the buffered writer
	def Flush(self):
		self.writer.flush() # Flush the writer to output

# PrintList prints a list of integers to the console
def PrintList(list):
	con = Console() # Create a new console instance
	defer con.Close() # Ensure flushing on function exit

	# Loop through the list and print each integer
	for i in range(len(list)):
		if i == 0:
			con.Printf("%d", list[i]) # Print the first element without a leading space
		else:
			con.Printf(" %d", list[i]) # Print subsequent elements with a leading space
	con.Println("") # Print a newline after the list

# main function where the program execution begins
def main():
	con = Console() # Create a new console instance
	defer con.Close() # Ensure flushing on function exit

	m = {} # Create a map to track unique integers
	lines = ReadLongLines(4) # Read 4 lines from input
	a = lines[1].split(" ") # Split the second line into individual strings

	# Convert strings to integers and store them in the map
	for i in range(len(a)):
		n = int(a[i]) # Convert string to integer
		m[n] = True # Add the integer to the map

	result = [] # Slice to hold the result integers
	b = lines[3].split(" ") # Split the fourth line into individual strings

	# Process the integers from the fourth line
	for i in range(len(b)):
		n = int(b[i]) # Convert string to integer
		if n in m: # Check if the integer exists in the map
			del m[n] # Remove it from the map if it exists
		else:
			m[n] = True # Add it to the map if it does not exist
	}

	# Collect remaining integers from the map into the result slice
	for k, _ in m.items():
		result.append(k) # Append the key to the result slice

	# Sort the result slice in ascending order
	result.sort()

	# Print the sorted result
	for j in range(len(result)):
		con.Printf("%d\n", result[j]) # Print each integer in the result

if __name__ == "__main__":
	main()

