import sys 
import math 

def main(): 
    # Read the number of elements (n) and the threshold (k) from input
    n, k = map(int, sys.stdin.readline().split()) 
    
    # Initialize an array to hold the input values
    bb = [0] * n 
    
    # Read n integers into the bb array
    for i in range(n): 
        bb[i] = int(sys.stdin.readline()) 
    
    # Initialize an array to hold the results and a counter for the results
    aa = [0] * n 
    m = 0 
    
    # Process the input array in reverse order
    for a in range(n - 1, -1, -1): 
        j = 0 
        # While there are still counts left for the current index in bb
        while bb[a] > 0: 
            # Check if the current index in aa is valid
            if aa[j] >= a + k: 
                bb[a] -= 1 
            j += 1 
        # Shift elements in aa to make space for the current index
        for j_ in range(m, j - 1, -1): 
            aa[j_] = aa[j_ - 1] 
        aa[j] = a 
    
    # Output the results, incrementing by 1 for 1-based indexing
    for i in range(n): 
        print(aa[i] + 1, end=" ") 
    
    print() 

if __name__ == "__main__": 
    main() 

