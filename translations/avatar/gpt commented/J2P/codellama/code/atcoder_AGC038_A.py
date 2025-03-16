import sys 

# Read the dimensions of the grid and the parameters A and B
H, W, A, B = map(int, sys.stdin.readline().split()) 

# Check if the grid can accommodate the required number of 0s and 1s
if W < 2 * A or H < 2 * B: 
    print(-1) 
    sys.exit() 

# Generate the grid based on the parameters A and B
for i in range(H): 
    for j in range(W): 
        # Determine whether to write '0' or '1' based on the current position
        if (i < B and j < A) or (i >= B and j >= A): 
            sys.stdout.write("0") 
        else: 
            sys.stdout.write("1") 
    sys.stdout.write("\n") 

# Flush the output to ensure all data is written out
sys.stdout.flush() 

# End of code
