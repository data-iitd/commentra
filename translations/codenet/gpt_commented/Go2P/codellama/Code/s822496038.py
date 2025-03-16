
# Importing the required modules
import sys

# Function to read the next integer from input
def nextInt():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read the number of apples and pieces from input
    appleNum = nextInt()
    pieceNum = nextInt()

    # Calculate the number of pieces made from apples (3 pieces per apple)
    pieceNumMadeFromApples = appleNum * 3

    # Calculate the total number of pieces (pieces from apples + existing pieces)
    totalPiece = pieceNumMadeFromApples + pieceNum

    # Output the total number of complete sets of 2 pieces
    print(totalPiece // 2)

# Call the main function
main()

