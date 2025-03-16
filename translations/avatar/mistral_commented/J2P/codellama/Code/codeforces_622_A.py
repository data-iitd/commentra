
import sys
import math

# Initialize constants
BUFFER_SIZE = 512000

# Initialize scanner and print writer
sc = sys.stdin
out = sys.stdout

# Main method
def main ( ):
    init() # Initialize input and output streams
    solve() # Solve the problem
    closeIO() # Close input and output streams

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx \* 2 ) < position ):
        nrstSeqStartIndx \*= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while ( getValueAtIndex( nrstSeqStartIndx + 1 ) <= position ):
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex( nrstSeqStartIndx ) # Get the start index of the sequence
    out.println( ( position - startIndex ) + 1 ) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex ( index ):
    return 1 + ( ( index - 1 ) \* index / 2 ) # Calculate the value at the given index

# Inner class for input handling
class in:
    def __init__( self ):
        pass

    # Read a string token from input
    def next( self ):
        pass

    # Read an integer from input
    def nextInt( self ):
        pass

    # Read a double from input
    def nextDouble( self ):
        pass

    # Read a long from input
    def nextLong( self ):
        pass

# Initialize input and output streams
def init ( ):
    pass

# Close input and output streams
def closeIO ( ):
    pass

# Solve the problem
def solve ( ):
    position = sc.nextLong() # Read the position from input
    solveHelper( position ) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper ( position ):
    nrstSeqStartIndx = 1 # Initialize index for the sta