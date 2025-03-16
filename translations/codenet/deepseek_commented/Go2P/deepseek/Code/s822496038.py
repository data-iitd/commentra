import sys

# This is the global scanner used to read input from the standard input.
sc = sys.stdin

# nextInt reads a single word from the standard input, converts it to an integer, and returns it.
# It panics if the conversion fails.
def nextInt():
    word = sc.readline()
    if not word:
        return None
    i, e = int(word), None
    if e is not None:
        raise e
    return i

# The main function is the entry point of the program.
def main():
    # Set the scanner to read words instead of lines.
    sc.readline = sys.stdin.readline
    
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

if __name__ == "__main__":
    main()
