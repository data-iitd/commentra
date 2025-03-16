import sys 
import math 

# Step 2: Define the Scanner and PrintWriter for input and output operations.
sc = sys.stdin 
out = sys.stdout 

# Step 3: Implement the solve method to find the position of a given value in a sequence.
def solve(): 
    position = int(sc.readline()) 
    nrstSeqStartIndx = 1 
    
    # Step 4: Find the starting index of the sequence where the position might be located.
    while getValueAtIndex(nrstSeqStartIndx * 2) < position: 
        nrstSeqStartIndx *= 2 
    
    # Step 4: Find the exact position within the sequence.
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position: 
        nrstSeqStartIndx += 1 
    
    startIndex = getValueAtIndex(nrstSeqStartIndx) 
    out.write(str(position - startIndex + 1) + "\n") 

# Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
def getValueAtIndex(index): 
    return 1 + ((index - 1) * index / 2) 

# Step 5: Implement the main method to initialize the input and call the solve method.
def main(): 
    # Step 7: Initialize the input reader for the in class.
    in.init(sys.stdin) 
    solve() 
    out.close() 

# Step 7: Implement the in class to handle input operations.
class in: 
    reader = sys.stdin 
    tokenizer = str.split() 
    
    def init(input): 
        reader = sys.stdin 
        tokenizer = str.split() 
    
    def next(): 
        while not tokenizer: 
            tokenizer = str.split(reader.readline()) 
        return tokenizer.pop(0) 
    
    def nextInt(): 
        return int(next()) 
    
    def nextDouble(): 
        return float(next()) 
    
    def nextLong(): 
        return long(next()) 

# Step 8: End the code with "