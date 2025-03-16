
import sys

def main():
    # Initialize input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Read the input string
    s = input_stream.readline().strip()

    # Check if the string contains both 'A' and 'B'
    if 'A' in s and 'B' in s:
        # If both characters are present, print "Yes"
        output_stream.write("Yes\n")
    else:
        # If either character is missing, print "No"
        output_stream.write("No\n")

if __name__ == "__main__":
    main()
