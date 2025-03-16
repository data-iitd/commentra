import sys

# Initialize constants
BUFFER_SIZE = 512000

# Initialize input and output streams
input_stream = sys.stdin
output_stream = sys.stdout

# Function to get the value at a given index
def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)  # Calculate the value at the given index

# Function to solve the problem
def solve():
    position = int(input_stream.readline().strip())  # Read the position from input
    solve_helper(position)  # Solve the problem using helper method

# Helper function to solve the problem
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
    output_stream.write(f"{(position - start_index) + 1}\n")  # Print the length of the sequence

# Main function
if __name__ == "__main__":
    solve()  # Solve the problem

# <END-OF-CODE>
