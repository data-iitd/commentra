import sys

def main():
    # Initialize input and output
    inp = sys.stdin.readline
    out = sys.stdout.write
    
    n = int(inp())  # Read the size of the grid
    square = n * n  # Calculate the total number of elements
    
    odd = []  # List to store odd numbers
    even = []  # List to store even numbers
    
    # Separating numbers into odd and even lists
    for i in range(1, square + 1):
        if i % 2 == 0:
            even.append(i)  # Add even numbers to the even list
        else:
            odd.append(i)  # Add odd numbers to the odd list
    
    loop = square // n  # Calculate the number of rows/columns
    div = loop // 2  # Calculate half the number of elements in each row/column
    
    # Nested loops to generate the pattern
    for i in range(1, loop + 1):
        for j in range(div):
            if i % 2 == 1:
                out(f"{odd.pop(0)} {even.pop()} ")  # Print odd and even numbers in reverse order for odd rows
            else:
                out(f"{even.pop(0)} {odd.pop()} ")  # Print even and odd numbers in reverse order for even rows
        out("\n")  # Move to the next line after each row

if __name__ == "__main__":
    main()
