import sys
from collections import Counter

def main():
    # Initialize input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Read the first line of input
    str = input_stream.readline().strip()

    # Initialize the map to store character counts
    map = Counter(str)

    # Count the number of characters with odd counts
    odd_count = sum(1 for count in map.values() if count % 2 != 0)

    # Determine the output based on the odd count
    if odd_count <= 1 or odd_count % 2 != 0:
        output_stream.write("First\n")  # Output "First" if the odd count is 1 or odd
    else:
        output_stream.write("Second\n")  # Output "Second" if the odd count is even

if __name__ == "__main__":
    main()
