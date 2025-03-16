
# Initialize a new scanner for reading input from stdin
sc = bufio.NewScanner(sys.stdin)

# Function to read an integer from the standard input
def nextInt():
    # Scan the next word from the standard input
    sc.Scan()
    # Parse the scanned text as an integer
    i = int(sc.Text())
    # Return the parsed integer
    return i

# Main function
if __name__ == "__main__":
    # Set the scanner to split input on words
    sc.Split(bufio.ScanWords)
    # Read the number of apples from the standard input
    appleNum = nextInt()
    # Read the number of pieces to be made from apples from the standard input
    pieceNum = nextInt()
    # Calculate the number of pieces made from apples
    pieceNumMadeFromApples = appleNum * 3
    # Calculate the total number of pieces
    totalPiece = pieceNumMadeFromApples + pieceNum
    # Print the total number of pieces divided by 2
    print(totalPiece / 2)
    # End of the code

