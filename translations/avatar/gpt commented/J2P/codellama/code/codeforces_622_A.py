import sys 
import math 

# Define a constant for the buffer size used in input and output operations
BUFFERSIZE = 512000 

# Initialize a Scanner for reading input with a buffered reader for efficiency
sc = sys.stdin 

# Initialize a PrintWriter for output with a buffered output stream for efficiency
out = sys.stdout 

# Method to solve the main problem
def solve(): 
    # Read the position from input
    position = int(sc.readline()) 
    
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
    out.write(str(position - startIndex + 1) + "\n") 

# Method to calculate the value at a given index based on a specific formula
def getValueAtIndex(index): 
    return 1 + ((index - 1) * index / 2) 

# Main method to execute the program
def main(): 
    # Initialize the input reader
    in.init(sys.stdin) 
    
    # Call the solve method to process the input and produce output
    solve() 
    
    # Close the output stream
    out.close() 

# Static inner class for handling input operations
class in: 
    reader = sys.stdin 
    tokenizer = str.split() 
    
    # Method to initialize the input reader
    def init(input): 
        reader = sys.stdin 
        tokenizer = str.split() 
    
    # Method to get the next token from input
    def next(): 
        # Ensure there are tokens available to read
        while not tokenizer: 
            tokenizer = str.split(reader.readline()) 
        return tokenizer.pop(0) 
    
    # Method to get the next integer from input
    def nextInt(): 
        return int(next()) 
    
    # Method to get the next double from input
    def nextDouble(): 
        return float(next()) 
    
    # Method to get the next long from input
    def nextLong(): 
        return long(next()) 

# END-OF-CODE
