import sys
import math

# Define a constant for the buffer size used in input and output operations
BUFFERSIZE = 512000

# Initialize a Scanner for reading input with a buffered reader for efficiency
sc = Scanner(sys.stdin, BUFFERSIZE)

# Initialize a PrintWriter for output with a buffered output stream for efficiency
out = PrintWriter(sys.stdout, BUFFERSIZE)

# Method to solve the main problem
def solve():
    # Read the position from input
    position = sc.nextLong()
    
    # Initialize the nearest sequence start index
    nrstSeqStartIndx = 1
    
    # Find the nearest sequence start index such that its value is less than the position
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2
    
    # Increment the nearest sequence start index until its value exceeds the position
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1
    
    # Get the starting index value for the nearest sequence
    startIndex = getValueAtIndex(nrstSeqStartIndx)
    
    # Output the result, which is the difference between the position and the start index plus one
    out.println((position - startIndex) + 1)

# Method to calculate the value at a given index based on a specific formula
def getValueAtIndex(index):
    return 1 + ((index - 1) * index / 2)

# Main method to execute the program
if __name__ == '__main__':
    # Initialize the input reader
    in.init(sys.stdin)
    
    # Call the solve method to process the input and produce output
    solve()
    
    # Close the output stream
    out.close()

# Static inner class for handling input operations
class in:
    reader = None # BufferedReader for reading input
    tokenizer = None # Tokenizer for parsing input
    
    # Method to initialize the input reader
    def init(self, input):
        self.reader = BufferedReader(InputStreamReader(input), BUFFERSIZE)
        self.tokenizer = StringTokenizer("")
    
    # Method to get the next token from input
    def next(self):
        # Ensure there are tokens available to read
        while not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()
    
    # Method to get the next integer from input
    def nextInt(self):
        return int(self.next())
    
    # Method to get the next double from input
    def nextDouble(self):
        return float(self.next())
    
    # Method to get the next long from input
    def nextLong(self):
        return long(self.next())

