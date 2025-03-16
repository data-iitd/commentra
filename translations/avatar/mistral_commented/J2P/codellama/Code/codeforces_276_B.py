
import sys

def main():
    # Initialize input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Read the first line of input
    str = input_stream.readline()

    # Initialize the map to store character counts
    map = {}

    # Iterate through each character in the input string
    for i in range(len(str)):
        ch = str[i]  # Get the current character

        # If the character is already in the map, increment its count
        if ch in map:
            map[ch] += 1
        else:
            # Otherwise, add the character to the map with a count of 1
            map[ch] = 1

    # Iterate through each entry in the map and count odd-valued entries
    odd_count = 0
    for ch, count in map.items():
        if count % 2 != 0:
            odd_count += 1

    # Determine the output based on the odd count
    if odd_count <= 1 or odd_count % 2 != 0:
        output_stream.write("First\n")  # Output "First" if the odd count is 1 or odd
    else:
        output_stream.write("Second\n")  # Output "Second" if the odd count is even

    # Flush the output buffer to write the output to the console
    output_stream.flush()

if __name__ == "__main__":
    main()

