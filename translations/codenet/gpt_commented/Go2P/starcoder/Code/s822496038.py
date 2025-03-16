import sys

# Initialize a new scanner to read from standard input
sc = bufio.NewScanner(sys.stdin)

# Function to read the next integer from input
def nextInt():
    sc.scan() # Read the next token from input
    i, e = int(sc.text()), None # Convert the token to an integer
    if e!= None: # Check for conversion errors
        raise e # Panic if there is an error
    return i # Return the converted integer

# Read the number of apples and pieces from input
appleNum = nextInt()
pieceNum = nextInt()

# Calculate the number of pieces made from apples (3 pieces per apple)
pieceNumMadeFromApples = appleNum * 3

# Calculate the total number of pieces (pieces from apples + existing pieces)
totalPiece = pieceNumMadeFromApples + pieceNum

# Output the total number of complete sets of 2 pieces
print(totalPiece / 2)

# 