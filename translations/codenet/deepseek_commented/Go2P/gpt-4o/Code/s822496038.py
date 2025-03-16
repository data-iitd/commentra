import sys

# This function reads a single integer from standard input.
def next_int():
    return int(sys.stdin.readline().strip())

# The main function is the entry point of the program.
def main():
    # Read the number of apples.
    apple_num = next_int()
    
    # Read the number of pieces.
    piece_num = next_int()
    
    # Calculate the total pieces that can be made from the apples.
    piece_num_made_from_apples = apple_num * 3
    
    # Add the given pieces to the pieces made from apples.
    total_piece = piece_num_made_from_apples + piece_num
    
    # Print half of the total pieces.
    print(total_piece // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
