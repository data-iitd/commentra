

import sys
# Import necessary modules for input/output operations and utility classes.

def main():
    input = sys.stdin.read() # Read the input from the system.
    output = [] # Initialize an empty list to store the output.
    s = input.strip().replace("BC", "D")
    # Read the input string and replace all occurrences of "BC" with "D".
    cnt = 0 # Initialize a counter to keep track of the result.
    tmp = 0 # Temporary variable to count consecutive 'A's.
    for i in range(len(s)):
        if s[i] == "A":
            tmp += 1 # Increment tmp if the current character is 'A'.
        elif s[i] == "D":
            cnt += tmp # Add tmp to cnt if the current character is 'D'.
        else:
            tmp = 0 # Reset tmp if the current character is not 'A' or 'D'.
    output.append(str(cnt)) # Append the final count to the output list.
    print("\n".join(output)) # Print the output list.

if __name__ == "__main__":
    main()
# The main function reads the input, processes it, and prints the output.

Translate the above Python code to C++ and end with comment "