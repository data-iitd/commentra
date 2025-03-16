
# Initialize a new scanner for reading input from stdin
sc = input()

# Function to read an integer from the standard input
def nextInt():
    # Scan the next word from the standard input
    sc.split()
    # Parse the scanned text as an integer
    i = int(sc)
    # If parsing fails, panic with the error
    if err != None:
        panic(err)
    # Return the parsed integer
    return i

# Main function
def main():
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


