import sys

BUFFERSIZE = 512000

# Step 3: Implement the solve function to find the position of a given value in a sequence.
def solve():
    position = int(sys.stdin.readline().strip())
    nrst_seq_start_indx = 1

    # Step 4: Find the starting index of the sequence where the position might be located.
    while get_value_at_index(nrst_seq_start_indx * 2) < position:
        nrst_seq_start_indx *= 2

    # Step 4: Find the exact position within the sequence.
    while get_value_at_index(nrst_seq_start_indx + 1) <= position:
        nrst_seq_start_indx += 1

    start_index = get_value_at_index(nrst_seq_start_indx)
    print((position - start_index) + 1)

# Step 4: Implement the get_value_at_index function to calculate the value at a specific index in the sequence.
def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)

# Step 5: Implement the main function to initialize the input and call the solve function.
if __name__ == "__main__":
    solve()

# <END-OF-CODE>
