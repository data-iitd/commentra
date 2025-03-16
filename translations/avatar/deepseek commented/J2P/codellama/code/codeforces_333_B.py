import sys ; 
import math ; 

# FastReader object to read input efficiently
in = sys.stdin ; 

# PrintWriter object to output the result
out = sys.stdout ; 

def main(): 
    # Read the dimensions of the grid
    n = int(in.readline()) ; 
    # Read the number of banned cells
    m = int(in.readline()) ; 

    # Initialize sets to keep track of banned rows and columns
    bannedRows, bannedCols = set(), set() ; 

    # Read each banned cell and add it to the appropriate set if it's not on the border
    for i in range(m): 
        r, c = map(int, in.readline().split()) ; 
        if r > 1 and r < n: 
            bannedRows.add(r) ; 
        if c > 1 and c < n: 
            bannedCols.add(c) ; 

    # Calculate the number of cells that can be reached, accounting for banned rows and columns
    answer = (n - 2) * 2 ; 
    answer -= len(bannedRows) ; 
    answer -= len(bannedCols) ; 

    # Adjust the answer if the grid size is odd and the center cell is not banned
    if n % 2 != 0: 
        mid = (n + 1) / 2 ; 
        if mid not in bannedRows and mid not in bannedCols: 
            answer -= 1 ; 

    # Output the final answer
    out.write(str(answer) + "\n") ; 
    # Close the output stream
    out.close() ; 

if __name__ == "__main__": 
    main() ; 

