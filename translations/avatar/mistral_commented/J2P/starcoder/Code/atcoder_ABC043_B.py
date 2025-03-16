
import sys # Input/output system

# Main function
def main():
    # Read the input
    s = sys.stdin.readline().strip()

    # Initialize the output
    d = ""

    # Iterate through each character in the input
    for c in s:
        # Switch statement to handle different characters
        if c == "0":
            d += "0" # Append "0" to the output
        elif c == "1":
            d += "1" # Append "1" to the output
        elif c == "B":
            if len(d) > 0: # If there is a character in the output
                d = d[:-1] # Remove the last character from the output
                d = d.strip() # Trim the size of the output to the new length

    # Print the output
    print(d)

# Main execution
if __name__ == "__main__":
    main()

