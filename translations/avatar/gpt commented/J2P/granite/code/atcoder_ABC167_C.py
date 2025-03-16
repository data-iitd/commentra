
import sys

def main():
    # Read the number of rows (n), columns (m), and the minimum required value (x)
    n, m, x = map(int, input().split())
    
    # Initialize a 2D array to store the input values
    a = [list(map(int, input().split())) for _ in range(n)]
    
    # Initialize the minimum value to a large number
    min_val = sys.maxsize
    
    # Iterate through all possible combinations of rows using bit manipulation
    for i in range(2**n):
        # Create an array to track which rows are included in the current combination
        status = [int(bit) for bit in bin(i)[2:].zfill(n)]
        
        # Initialize an array to store the sum of the selected rows
        res = [0] * (m + 1)
        
        # Calculate the sum of the selected rows
        for j in range(n):
            if status[j] == 1:
                for k in range(m + 1):
                    res[k] += a[j][k]
        
        # Check if the current combination meets the minimum requirement for each column
        if all(val >= x for val in res[1:]):
            # If the combination is valid, update the minimum value found
            min_val = min(min_val, res[0])
    
    # Output the result: -1 if no valid combination was found, otherwise the minimum value
    if min_val == sys.maxsize:
        print(-1)
    else:
        print(min_val)

if __name__ == "__main__":
    main()

