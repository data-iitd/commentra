
import sys

def solve(testNumber, in, out):
    s = in.readline().replace("BC", "D")
    # Read the input string and replace all occurrences of "BC" with "D".
    cnt = 0
    # Initialize a counter to keep track of the result.
    tmp = 0
    # Temporary variable to count consecutive 'A's.
    for i in range(len(s)):
        if s[i] == "A":
            tmp += 1
            # Increment tmp if the current character is 'A'.
        elif s[i] == "D":
            cnt += tmp
            # Add tmp to cnt if the current character is 'D'.
        else:
            tmp = 0
            # Reset tmp if the current character is not 'A' or 'D'.
    out.write(str(cnt) + "\n")
    # Print the final count.

if __name__ == "__main__":
    solve(1, sys.stdin, sys.stdout)
    # Call the solve method with input and output streams.

