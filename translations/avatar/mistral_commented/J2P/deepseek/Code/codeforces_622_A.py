import sys
import io

BUFFER_SIZE = 512000

# Initialize scanner and print writer
sc = io.TextIOWrapper(sys.stdin.buffer, BUFFER_SIZE)
out = io.TextIOWrapper(sys.stdout.buffer, BUFFER_SIZE)

# Main method
def main():
    init()  # Initialize input and output streams
    solve()  # Solve the problem
    closeIO()  # Close input and output streams

# Initialize input and output streams
def init():
    sc.readline()  # Initialize input stream

# Close input and output streams
def closeIO():
    sc.close()  # Close input stream
    out.close()  # Close output stream

# Solve the problem
def solve():
    position = int(sc.readline().strip())  # Read the position from input
    solve_helper(position)  # Solve the problem using helper method

# Helper method to solve the problem
def solve_helper(position):
    nrst_seq_start_indx = 1  # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while get_value_at_index(nrst_seq_start_indx * 2) < position:
        nrst_seq_start_indx *= 2  # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while get_value_at_index(nrst_seq_start_indx + 1) <= position:
        nrst_seq_start_indx += 1  # Increment index

    # Print the answer
    start_index = get_value_at_index(nrst_seq_start_indx)  # Get the start index of the sequence
    out.write(f"{(position - start_index) + 1}\n")  # Print the length of the sequence

# Get the value at a given index
def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)  # Calculate the value at the given index

if __name__ == "__main__":
    main()

