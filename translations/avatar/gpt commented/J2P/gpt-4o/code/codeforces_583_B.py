# Importing the necessary module for reading input
import sys

def main():
    # Loop to process multiple test cases until there is no more input
    for line in sys.stdin:
        # Read the number of elements
        n = int(line.strip())
        
        # Initialize two lists to store the input values and a status flag
        a = [0] * n  # List to store the input values
        b = [0] * n  # List to track which elements have been processed
        
        # Initialize a counter for the number of steps taken
        s = -1  # Start with -1 to account for the first increment
        
        # Read the input values into list 'a'
        a = list(map(int, input().strip().split()))
        
        # Initialize variables for processing
        tem = 1  # Variable to alternate between forward and backward processing
        q = 0    # Counter for the number of processed elements
        
        # Loop until all elements have been processed
        while q != n:
            s += 1  # Increment the step counter
            
            # Check the direction of processing based on 'tem'
            if tem == 1:
                # Process elements from the start of the list
                for i in range(n):
                    # If the current element can be processed
                    if a[i] <= q and b[i] == 0:
                        b[i] = 1  # Mark the element as processed
                        q += 1    # Increment the processed counter
                tem = 0  # Switch to backward processing for the next iteration
            else:
                # Process elements from the end of the list
                for i in range(n - 1, -1, -1):
                    # If the current element can be processed
                    if a[i] <= q and b[i] == 0:
                        b[i] = 1  # Mark the element as processed
                        q += 1    # Increment the processed counter
                tem = 1  # Switch to forward processing for the next iteration
        
        # Output the total number of steps taken to process all elements
        print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
