# Import necessary classes
import sys

# Initialize input and output streams
def main():
    # Read input from stdin
    input_line = sys.stdin.readline().strip()
    
    # Process the input as needed
    # For example, let's assume we need to split the input by spaces
    tokens = input_line.split()
    
    # Output the result
    for token in tokens:
        print(token)

# Call the main function
if __name__ == "__main__":
    main()
