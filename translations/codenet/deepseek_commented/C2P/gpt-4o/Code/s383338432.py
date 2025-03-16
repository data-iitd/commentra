# Import the sys module for standard input
import sys

def main():
    # Read height and width from user input
    height, width = map(int, sys.stdin.readline().split())
    
    # Print the top border of the output
    print('#' * (width + 2))
    
    # Read and print each line of input with borders
    for _ in range(height):
        input_str = sys.stdin.readline().strip()  # Read a string from the user
        print(f'#{input_str}#')  # Print the string with borders
    
    # Print the bottom border of the output
    print('#' * (width + 2))

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
