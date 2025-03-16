

import sys

# Import statements: These are importing necessary modules from Python's standard libraries.

def main():
    input = sys.stdin.read() # Reading the input from the console.
    output = "" # Initializing the output string.
    s = input.strip() # Stripping any leading or trailing whitespace from the input string.
    if "A" in s and "B" in s: # Checking if the string contains both 'A' and 'B'.
        output += "Yes\n" # Appending "Yes" to the output string.
    else:
        output += "No\n" # Appending "No" to the output string.
    sys.stdout.write(output) # Writing the output to the console.

# Main function: This is the entry point of the program.

if __name__ == "__main__":
    main() # Calling the main function to execute the program.

# 