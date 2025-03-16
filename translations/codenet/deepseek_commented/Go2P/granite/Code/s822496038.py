

# This is the global scanner used to read input from the standard input.
sc = bufio.NewScanner(os.Stdin)

# nextInt reads a single word from the standard input, converts it to an integer, and returns it.
# It panics if the conversion fails.
def nextInt():
    sc.scan()
    i = int(sc.text())
    return i

# The main function is the entry point of the program.
def main():
    # Set the scanner to read words instead of lines.
    sc.split(bufio.ScanWords)
    
    # Read the number of apples.
    appleNum = nextInt()
    
    # Read the number of pieces.
    pieceNum = nextInt()
    
    # Calculate the total pieces that can be made from the apples.
    pieceNumMadeFromApples = appleNum * 3
    
    # Add the given pieces to the pieces made from apples.
    totalPiece = pieceNumMadeFromApples + pieceNum
    
    # Print half of the total pieces.
    print(totalPiece // 2)

