import sys

# Function to read an integer from the standard input
def next_int():
    # Read the next line from the standard input
    line = sys.stdin.readline()
    # Parse the line as an integer
    i = int(line.strip())
    # Return the parsed integer
    return i

# Main function
def main():
    # Read the number of apples from the standard input
    apple_num = next_int()
    # Read the number of pieces to be made from apples from the standard input
    piece_num = next_int()
    # Calculate the number of pieces made from apples
    piece_num_made_from_apples = apple_num * 3
    # Calculate the total number of pieces
    total_piece = piece_num_made_from_apples + piece_num
    # Print the total number of pieces divided by 2
    print(total_piece // 2)

# Call the main function
if __name__ == "__main__":
    main()
