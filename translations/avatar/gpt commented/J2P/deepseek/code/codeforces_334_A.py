import sys

def main():
    # Create a Scanner object for input and a PrintWriter for output
    inp = sys.stdin
    outp = sys.stdout
    
    # Read an integer n from input
    n = int(inp.readline().strip())
    
    # Calculate the square of n
    square = n * n
    
    # Initialize lists to hold odd and even numbers
    odd = []
    even = []
    
    # Populate the odd and even lists with numbers from 1 to square
    for i in range(1, square + 1):
        if i % 2 == 0:
            even.append(i)  # Add to even list if the number is even
        else:
            odd.append(i)  # Add to odd list if the number is odd
    
    # Calculate the number of loops and the division for pairing
    loop = square // n
    div = loop // 2
    
    # Debug output to check the value of div
    debug(div)
    
    # Loop through the number of rows to print the pairs
    for i in range(1, loop + 1):
        # For each row, print div pairs of numbers
        for j in range(div):
            # Alternate between odd and even pairs based on the row number
            if i % 2 == 1:
                # For odd rows, print an odd number and the last even number
                outp.write(str(odd.pop(0)) + " " + str(even.pop(-1)) + " ")
            else:
                # For even rows, print an even number and the last odd number
                outp.write(str(even.pop(0)) + " " + str(odd.pop(-1)) + " ")
        # Move to the next line after printing pairs for the current row
        outp.write("\n")
    
    # Close the PrintWriter to flush the output
    outp.close()

def debug(obj):
    print(obj, file=sys.stderr)

if __name__ == "__main__":
    main()
