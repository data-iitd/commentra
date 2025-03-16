import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())  # Read a line, strip whitespace, and convert to int

def main():
    # Read the number of apples and pieces from input
    apple_num = next_int()
    piece_num = next_int()
    
    # Calculate the number of pieces made from apples (3 pieces per apple)
    piece_num_made_from_apples = apple_num * 3
    
    # Calculate the total number of pieces (pieces from apples + existing pieces)
    total_piece = piece_num_made_from_apples + piece_num
    
    # Output the total number of complete sets of 2 pieces
    print(total_piece // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
