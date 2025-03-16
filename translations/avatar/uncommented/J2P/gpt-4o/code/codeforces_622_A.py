import sys

BUFFERSIZE = 512000

def get_value_at_index(index):
    return 1 + ((index - 1) * index // 2)

def solve():
    position = int(sys.stdin.readline().strip())
    nrst_seq_start_indx = 1
    
    while get_value_at_index(nrst_seq_start_indx * 2) < position:
        nrst_seq_start_indx *= 2
    
    while get_value_at_index(nrst_seq_start_indx + 1) <= position:
        nrst_seq_start_indx += 1
    
    start_index = get_value_at_index(nrst_seq_start_indx)
    print((position - start_index) + 1)

if __name__ == "__main__":
    solve()

# <END-OF-CODE>
