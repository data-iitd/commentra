import sys

# Define a constant for the buffer size used in input and output operations
BUFFERSIZE = 512000

# Method to calculate the value at a given index based on a specific formula
def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)

# Method to solve the main problem
def solve():
    # Read the position from input
    position = int(sys.stdin.readline().strip())
    
    # Initialize the nearest sequence start index
    nrst_seq_start_indx = 1
    
    # Find the nearest sequence start index such that its value is less than the position
    while get_value_at_index(nrst_seq_start_indx * 2) < position:
        nrst_seq_start_indx *= 2
    
    # Increment the nearest sequence start index until its value exceeds the position
    while get_value_at_index(nrst_seq_start_indx + 1) <= position:
        nrst_seq_start_indx += 1
    
    # Get the starting index value for the nearest sequence
    start_index = get_value_at_index(nrst_seq_start_indx)
    
    # Output the result, which is the difference between the position and the start index plus one
    print((position - start_index) + 1)

# Main method to execute the program
if __name__ == "__main__":
    solve()

# <END-OF-CODE>
