
import sys

def solve(testNumber, in, out):
    # Method for solving the problem

    s = in.readline().replace("BC", "D") # Replace all occurrences of "BC" with "D" in the input string

    cnt = 0 # Initialize counter for the number of "D"s
    tmp = 0 # Initialize temporary variable for counting consecutive "A"s

    for i in range(len(s)):
        # Loop through each character in the string

        if s[i] == "A":
            # If the character is "A", increment the temporary counter
            tmp += 1
        elif s[i] == "D":
            # If the character is "D", add the temporary counter to the total count
            cnt += tmp
        else:
            # If the character is neither "A" nor "D", reset the temporary counter
            tmp = 0

    # Print the result
    out.write(str(cnt) + "\n")

if __name__ == "__main__":
    # Main method that starts the program

    inputStream = sys.stdin # Input stream for reading from the console
    outputStream = sys.stdout # Output stream for writing to the console
    in = inputStream.readline # Create a new scanner for reading input
    out = outputStream.write # Create a new print writer for writing output

    solver = BABC() # Create a new instance of the BABC class
    solver.solve(1, in, out) # Solve the problem and print the result

    out.close() # Close the print writer to flush the output buffer

