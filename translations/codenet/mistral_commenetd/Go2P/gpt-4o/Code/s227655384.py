# Import necessary modules
import sys

# Function to read long lines from standard input
def read_long_lines(times):
    result = []
    buffer = []
    
    for _ in range(times):
        line = []
        while True:
            # Read a line from standard input
            read_line = sys.stdin.readline()
            if not read_line:  # End of input
                break
            line.append(read_line.rstrip('\n'))
            if read_line.endswith('\n'):
                break
        result.append(''.join(line))
    
    return result

# Function to print a list of integers
def print_list(lst):
    print(" ".join(map(str, lst)))

# Main function
def main():
    # Initialize an empty set to store unique integers
    unique_numbers = set()
    
    # Read long lines from the standard input
    lines = read_long_lines(4)
    
    # Split the second line into a list of integers
    a = map(int, lines[1].split())
    unique_numbers.update(a)

    # Read integers from the fourth line and add them to the set
    b = map(int, lines[3].split())
    unique_numbers.update(b)

    # Convert the set to a sorted list
    result = sorted(unique_numbers)

    # Print the sorted unique integers
    print_list(result)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
