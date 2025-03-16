import sys

def main():
    # Create a Scanner object for input and a PrintWriter for output
    inp = sys.stdin
    out = sys.stdout
    
    # Read the number of elements
    n = int(inp.readline().strip())
    
    # Initialize a list to store the input integers
    list_ = list(map(int, inp.readline().strip().split()))
    
    # Sort the list of integers in ascending order
    list_.sort()
    
    # Initialize a counter to track the maximum consecutive integer
    c = 1
    
    # Iterate through the sorted list to find the maximum consecutive integer
    for num in list_:
        # If the current integer is greater than or equal to the counter, increment the counter
        if num >= c:
            c += 1
    
    # Print the result which is the maximum consecutive integer found
    out.write(str(c) + '\n')
    
    # Close the PrintWriter
    out.close()

if __name__ == "__main__":
    main()
